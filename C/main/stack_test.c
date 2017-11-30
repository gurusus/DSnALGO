// Evaluate the expression "(2 + ( 3 + (5 * 3) ) )" using stack
#include "lib/stack.h"

int main()
{
  //char *expr="(2 + ( 3 + (5 * 3) ) )";
  //struct stack *o_s=(struct stack*) stack_create(32);; // Operation Stack
  struct stack* s1 = stack_create(32);
  for(int i=0; i<35; i++)
     push(s1, i);
  for(int i=0; i<35; i++)
    printf("%d  ",pop(s1));
  printf("\r\n");
  return 1;
}
