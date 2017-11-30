#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <inttypes.h>

struct queue{
  uint32_t queue_size;
  uint32_t size;
  struct node* head;
  struct node* tail;
};

extern struct queue*
queue_create(uint32_t size);

void 
queue_destroy(struct queue** s);

//Push
extern int8_t 
enqueue(struct queue *pqueue, int data);

//Push
extern int8_t 
dequeue(struct queue *pqueue);

extern int8_t
isFull(struct queue *pqueue);

extern int8_t
isEmpty(struct queue *pstack);

#endif
