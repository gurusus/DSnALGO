#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

struct node{
	int data;
	struct node *l;
	struct node *r;
};

struct node *t=NULL;
void dump_tree_in(struct node* root){
	if(!root) return;
	dump_tree_in(root->l);
	printf("%d\r\n", root->data);
	dump_tree_in(root->r);
}
void dump_tree_pre(struct node* root){
	if(!root) return;
	printf("%d\r\n", root->data);
	dump_tree_pre(root->l);
	dump_tree_pre(root->r);
}
void dump_tree_post(struct node* root){
	if(!root) return;
	dump_tree_post(root->l);
	dump_tree_post(root->r);
	printf("%d\r\n", root->data);
}
void dump_tree_level(struct node* root){
	if(!root) return;
	printf("Not Implemented\r\n");
}
int 
insert_node(struct node **t, int data){
    if(!t) return -1;
    struct node* root = *t;
    if(!root) {
	struct node* n = (struct node*) calloc(1, sizeof(struct node));
	n->data = data;
	n->l = n->r = NULL;
	*t = n;
	return 0;
    }
    if ( data < root->data ){
	    insert_node(&root->l, data);
    } 
    if ( data > root->data ){
	    insert_node(&root->r, data);
    }
    return 0;
}

struct node* 
find_min(struct node* root){
    if(!root) 
	return NULL;
    if(root->l)
       lmin = find_min(root->l, root->data);
    if(root->r)
       rmin = find_min(root->r, root->data);
    return (root->data > lmin) ? (rmin>lmin?lmin:rmin) : (root->data > rmin: rmin:root->data)   
}

struct node* 
delete_node(struct node *root, int data){
    if(!root) return NULL;
    else if(data < root->data){
	root->l = delete_node(root->l, data);
    }
    else if(data > root->data){
	root->r = delete_node(root->r, data);
    }
    // found the node to be deleted
    else {
	// case 1: no child
	if ( root->l == NULL && root->r == NULL) {
	    free(root);
	    root=NULL;
	// case 2: one child
	} else if(root->l == NULL) {
	    struct node *t = root;
	    root = root->r;
	    free(t);
	} else if(root->r == NULL ) {
	     struct node *t = root;
	     root = root->l;
	     printf("Deleteing %d at %p\r\n", t->data, t);
	     free(t);
	// case 3: two children
	} else {
	     struct node* t = find_min(root->r);
	     root->data = t->data;
	     root->r = delete_node(root->r, t->data);
	}
    }
    return root;
}

struct node* 
find_node(struct node *root, int data){
    if(!root) { 
       printf("%d Not Found\r\n", data);
       return NULL;
    }
    if( root->data == data ) {
       printf("%p:%d\r\n",root, root->data);
       return root;
    }
    if(data < root->data) find_node(root->l, data);
    if(data > root->data) find_node(root->r, data);
    return NULL;
}

int 
FindHeight(struct node* root) {
    if(!root) return -1;
    int lh = FindHeight(root->l);
    int rh = FindHeight(root->r);
    return ((lh>rh)?lh:rh)+1;
}

int main(){
	printf("H : %d\r\n",FindHeight(t));		
	insert_node(&t, 8);
	printf("H : %d\r\n",FindHeight(t));		
	insert_node(&t, 1);
	insert_node(&t, 12);
	printf("H : %d\r\n",FindHeight(t));		
	insert_node(&t, 0);
	insert_node(&t, 100);
	printf("H : %d\r\n",FindHeight(t));		
	insert_node(&t, 5);
	insert_node(&t, 4);
	printf("H : %d\r\n",FindHeight(t));		
	printf("\r\n In Order Traversal\r\n");
	dump_tree_in(t);
	printf("\r\n Pre Order Traversal\r\n");
	dump_tree_pre(t);
	printf("\r\n Post Order Traversal\r\n");
	int i=0;
	for(i=0;i<100;i++) {
		insert_node(&t, rand()%100);
	        printf("H : %d\r\n",FindHeight(t));		
	}
	dump_tree_post(t);

        find_node(t, 10);
        find_node(t, 12);
        find_node(t, 100);
        find_node(t, 9);
        find_node(t, 8);
        find_node(t, 1);

	t = delete_node(t, 8);
	printf("H : %d\r\n",FindHeight(t));		
	t = delete_node(t, 0);
	printf("H : %d\r\n",FindHeight(t));		
	dump_tree_in(t);
	return 0;
}
