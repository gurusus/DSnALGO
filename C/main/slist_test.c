#include "lib/slist.h"

int A[] = {45, 18, 3, 15, 9, 1, 8, 14, 11, 4, 17, 7, 16, 6, 20, 5, 19, 2, 13, 12, 10};

struct node* slist=NULL;

int main()
{
  int len = sizeof(A)/sizeof(A[0]);
  struct node* ret=NULL;

  for (int i=0; i<len; i++) {
    ret = insert_tail(&slist, A[i]);
    if(!ret) printf("Failed to insert %d",i);
  }
  dump_slist(slist);
  reverse_slist(&slist);
  dump_slist(slist);
  alt_swap_slist(&slist);
  dump_slist(slist);
  //random_del(&slist);
  return 0;
}
