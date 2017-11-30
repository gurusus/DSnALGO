#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>

struct node{
   int data;
   struct node *next;
};

// LIFO - queue
extern struct node*
insert_head(struct node** l, int data);

// LIFO - queue
extern struct node*
insert_tail(struct node** l, int data);

extern struct node*
find_node(struct node* l, int data);

extern struct node*
insert_next(struct node** l, int find, int data);

extern void
del_node(struct node** l, int data);

extern void
del_head(struct node** h);

extern struct node*
del_tail(struct node** h);

extern void
del_slist(struct node** l);

extern void
dump_slist(struct node* h);

extern void
random_del(struct node** h);

extern void
reverse_slist(struct node** h);

extern void
alt_swap_slist(struct node** h);
