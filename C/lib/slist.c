#include "slist.h"

// LIFO - queue
struct node*
insert_head(struct node** l, int data){
   if(!l) return NULL;

   struct node* n = (struct node*) calloc(1, sizeof(struct node));
   if(!n) return NULL;
   n->data = data;
   n->next = NULL;

   if(*l) n->next = *l;
   *l = n;

   return n;
}

// LIFO - queue
struct node*
insert_tail(struct node** l, int data){
   if(!l) return NULL;

   struct node* n = (struct node*) calloc(1, sizeof(struct node));
   if(!n) return NULL;
   n->data = data;
   n->next = NULL;

   struct node *t=*l;
   // no elements in the list
   if (!t) {
      *l = n;
      return n;
   }

   // find the tail
   while(t->next)
      t=t->next;

   t->next = n;
   return n;
}

struct node*
find_node(struct node* l, int data){
   if(!l) return NULL;

   struct node *t=l;

   // find the tail
   while(t) {
      if(t->data == data)
         break;
      t=t->next;
   }

   return t;
}

struct node*
insert_next(struct node** l, int find, int data)
{
   if(!l) return NULL;

   struct node* f = find_node(*l, find);
   // node not found, return NULL
   if(!f) return NULL;

   // node found insert new element next to it.
   struct node* n = (struct node*) calloc(1, sizeof(struct node));
   if(!n) return NULL;
   n->data = data;
   n->next = NULL;

   if(f->next == NULL) {
      // node found is tail
      f->next = n;
   } else {
      struct node* t = f->next;
      n->next = t;
      f->next = n;
   }

   return n;
}

void
del_node(struct node** l, int data)
{
   if(!l) return;

   struct node* p = NULL;
   struct node* c = *l;

   if (!c) return;

   // if head
   if( c->data == data ) {
      c = c->next;
      free(*l);
      *l = c;
   } else {
      while(c) {
	 if(c->data == data) {
            p->next = c->next;
	    free(c);
	    c = NULL;
	    break;
	 } else {
	    p = c;
	    c = c->next;
	 }
      }
   }

   return ;
}

void
del_head(struct node** h) {
  struct node* t = *h;
  if(!h || !t)
    return;

  *h = (*h)->next;
  free(t);
  t = NULL;

  return ;
}

extern struct node*
del_tail(struct node** h) {
  struct node* p = NULL;
  struct node* c = *h;
  if(!h || !c)
    return NULL;

  if(!c->next) {
    free(c);
    return NULL;
  }
  
  while(c->next) {
      p = c;
      c = c->next;
  }
  free(c);
  p->next = NULL;
  return p;
}

void
dump_slist(struct node* h){
   while(h) {
      printf(" %3d ", h->data);
      h = h->next;
   }
   printf("\r\n");
   return;
}

void
random_del(struct node** h){
   if(!h || !*h) return;

   dump_slist(*h);
   while(*h) {
       int rn = rand() % 21;
       printf("trying to delete ele with val:%d\r\n",rn);
       del_node(h, rn);
       dump_slist(*h);
   }
   return;
}

void
del_slist(struct node** h){
 if(!h || !*h) return;

  while(*h) {
    del_head(h);
  }

  return;
}

void
reverse_slist(struct node** h){
   if(!h || !*h) return;

   struct node *c=*h, *p=NULL, *n=NULL;
   while(c) {
      n = c->next;
      c->next = p;
      p = c;
      c = n;
   }
   *h = p;

   return;
}

void
alt_swap_slist(struct node** h){
   if(!h || !*h) return;

   struct node *p=NULL, *c=*h, *n=NULL, *nn=NULL;
   while(c && c->next) {
      n = c->next;
      nn = n->next;
      n->next = c;
      c->next = nn;
      if(p)
        p->next = n;
      if ( *h == c )
        *h = n;
      p = c;
      c = nn;
   }
   if(c)
     p->next = c;

   return;
}
