// Evaluate the expression "(2 + ( 3 + (5 * 3) ) )" using stack
#include "lib/queue.h"
#include "lib/slist.h"

//isFull?
int8_t
isFull(struct queue* pqueue)
{
   return (pqueue->queue_size == pqueue->size);
}

//isEmpty?
int8_t
isEmpty(struct queue* pqueue)
{
   return (!pqueue->size);
}

//Constructor
struct queue*
queue_create(uint32_t size)
{
  struct queue* pq = NULL;
  if(size) {
    pq = (struct queue*) malloc(sizeof(struct queue));
    if(!pq)
      return NULL;
    pq->queue_size = size;
    pq->size = 0;
    pq->tail = pq->head = NULL;
  }
  return pq;
}

//Destructor
void
queue_destroy(struct queue** pqueue)
{
  if(pqueue && *pqueue) {
    struct queue* pq = (struct queue*)*pqueue;
    del_slist(&pq->head);
    pq->head = pq->tail = NULL;
    free(pq);
    pq = NULL;
  }
  return;
}

//Push
int8_t
enqueue(struct queue* pq, int data)
{  
  if(!pq) 
    return -EINVAL;

  if(insert_head(&pq->head, data)) {
    pq->size += 1;
    if(pq->size == 1)
      pq->tail = pq->head;
  }

  return pq->head->data;
}

//Push
int8_t
dequeue(struct queue* pqueue)
{
  struct queue *pq = (struct queue*) pqueue;
  int ret=0;
  
  if(!pq) 
    return -EINVAL;

  if(pq->tail != NULL){
    ret = pq->tail->data;
    pq->tail = del_tail(&pq->head);
    pq->size -= 1;    
  }
  
  return ret;
}
