#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <inttypes.h>

struct stack{
   uint32_t stack_size;
   uint32_t size;
   struct node* top;
};

extern struct stack*
stack_create(uint32_t size);

extern struct stack*
stack_destroy(struct stack** s);

//Push
extern int8_t 
push(struct stack *pstack, int data);

//Push
extern int8_t 
pop(struct stack *pstack);

extern int8_t
isFull(struct stack *pstack);

extern int8_t
isEmpty(struct stack *pstack);

#endif
