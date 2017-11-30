// Evaluate the expression "(2 + ( 3 + (5 * 3) ) )" using stack
#include "lib/stack.h"
#include "lib/slist.h"

//isFull?
int8_t
isFull(struct stack* pstack)
{
   return (pstack->stack_size == pstack->size);
}

//isEmpty?
int8_t
isEmpty(struct stack* pstack)
{
   return (!pstack->size);
}

//Constructor
struct stack*
stack_create(uint32_t size)
{
  struct stack* ps = NULL;
  if(size) {
    ps = (struct stack*) malloc(sizeof(struct stack));
    if(!ps)
      return NULL;
    ps->stack_size = size;
    ps->size = 0;
    ps->top = NULL;
  }
  return ps;
}

//Destructor
struct stack*
stack_destroy(struct stack** pstack)
{
  if(pstack && *pstack) {
    struct stack* ps = (struct stack*)*pstack;
    del_slist(&ps->top);
    ps->top = NULL;
    free(ps);
    ps = NULL;
  }
  return 0;
}

//Push
int8_t
push(struct stack* pstack, int data)
{
  struct stack *ps = (struct stack*) pstack;
  
  if(!ps) 
    return -EINVAL;

  if (!isFull(ps)) {
    if(insert_head(&ps->top, data))
      ps->size += 1;
  } else {
    return -1;
  }
  return 0;
}

//Push
int8_t
pop(struct stack* pstack)
{
  struct stack *ps = (struct stack*) pstack;
  int ret=0;
  
  if(!ps) 
    return -EINVAL;

  if (!isEmpty(ps)){
    ret = ps->top->data;
    del_head(&ps->top);
    ps->size -= 1;    
  }
  
  return ret;
}
