// Evaluate the expression "(2 + ( 3 + (5 * 3) ) )" using stack
#include "lib/queue.h"

int main()
{
  //char *expr="(2 + ( 3 + (5 * 3) ) )";
  //struct stack *o_s=(struct stack*) stack_create(32);; // Operation Stack
  struct queue* q1 = queue_create(32);
  for(int i=0; i<35; i++)
    printf("%d ", enqueue(q1, i));
  printf("\r\n");  

  for(int i=0; i<35; i++)
    printf("%d  ",dequeue(q1));
  printf("\r\n");
  return 1;
  
}
