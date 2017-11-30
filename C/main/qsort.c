#include <stdio.h>
#include <stdlib.h>

#define ASIZE(x) ((sizeof((x)))/(sizeof((x[0]))))
int D[] = {7, 2, 1};
int C[] = {7};
int B[] = {};
int A[] = {7, 2, 1, 6, 8, 5, 3, 4, 12, 40, 35, 21, 19, 13, 16, 9, 10, 17, 11, 15, 14, 18, 20};
int alen=0;

int 
Partition(int *A, int start, int end){
   int pivot = A[end];
   int pIndex = start;

   if ( end <= start ) 
       return 0;

   printf("%p:%d:%d\r\n",A, start, end);

   for(int i=start; i<end; i++) {
	if(A[i] < pivot) {
	   // Place all elements < pivot to the left 
	   // place all elements > pivot to the right
	   if (i != pIndex) {
	       A[i] = A[i] ^ A[pIndex];
	       A[pIndex] = A[i] ^ A[pIndex];
	       A[i] = A[i] ^ A[pIndex];
	   }
	   pIndex++;
	}
   }

   //place sorted pivot ar its place
   if (pIndex != end ) {
      A[pIndex] = A[pIndex] ^ A[end];
      A[end] = A[pIndex] ^ A[end];
      A[pIndex] = A[pIndex] ^ A[end];
   }
   
   // return the index of the pivot element
   return pIndex;
}

void
dump_A(int* A, int l, int r)
{
    int i = 0;
    for(i=l;i<=r;i++)
	printf("A[%d]:%d ",i, A[i]);
    printf("\r\n");
}

void 
my_qsort(int* A, int start, int end)
{
  dump_A(A, start, end);
    if(start >= end) 
        return;
    int pIndex = Partition(A, start, end);
    printf("start:%d,end:%d,pIndex:%d\r\n", start, end, pIndex);
    if(pIndex>start) my_qsort(A, start, pIndex-1);
    if(pIndex<end) my_qsort(A, pIndex+1, end);
}

void
merge(int* A, int l, int m, int r){
  int i=0, j=0, k=l;
  int n1 = m-l+1;
  int n2 = r-m;
  int L[n1];
  int R[n2];

  printf("\r\n Merging Begin...\r\n");
  //dump_A(A, l, r);
    // copy l...m and m+1...r elements into two arrays
  for(i=0;i<n1;i++) L[i] = A[i+l];
  //dump_A(L, 0, n1-1);
  for(j=0;j<n2;j++) R[j] = A[j+m+1];
  //dump_A(R, 0, n2-1);
  // merge two sub arrays
  i=0;
  j=0;
  k=l;
  //printf("L[%d]=%d, R[%d]=%d, k=%d, n1=%d, n2=%d\r\n",i,L[i],j,R[j],k,n1,n2);
  while(i<n1 && j<n2) {
    if(L[i] <= R[j]) {
      A[k++] = L[i++];
    } else {
      A[k++] = R[j++];
    }
  }
  //printf("i=%d, j=%d, k=%d, n1=%d, n2=%d\r\n",i,j,k,n1,n2);
  while(i<n1) A[k++] = L[i++];   
  //printf("i=%d, j=%d, k=%d, n1=%d, n2=%d\r\n",i,j,k,n1,n2);
  while(j<n2) A[k++] = R[j++];
  //printf("i=%d, j=%d, k=%d, n1=%d, n2=%d\r\n",i,j,k,n1,n2);
  //dump_A(A, l, r);
  //printf("\r\n Merging End...\r\n");
  
  return;
}

void 
my_msort(int* A, int l, int r){
  int m = l + (r-l)/2;
  dump_A(A, l, r);
  if(l<r) {
    my_msort(A, l, m);
    my_msort(A, m+1, r);
    merge(A, l, m, r);
  }
  return;
}

void
swap(int* x, int *y)
{
  *x = *x + *y;
  *y = *x - *y;
  *x = *x - *y;
}

void
max_heapify(int* A, int n, int i)
{
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;

  //if lchild > root
  if ( l < n && A[l] > A[largest] ) {
    largest = l;
  }

  //if rchild > root
  if ( r < n && A[r] > A[largest] ) {
    largest = r;
  }

  if ( largest != i ) {
    swap(&A[i], &A[largest]);
    max_heapify(A, n, largest);
  }
}

void
min_heapify(int* A, int n, int i)
{
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;

  //if lchild > root
  if ( l < n && A[l] < A[largest] ) {
    largest = l;
  }

  //if rchild > root
  if ( r < n && A[r] < A[largest] ) {
    largest = r;
  }

  if ( largest != i ) {
    swap(&A[i], &A[largest]);
    min_heapify(A, n, largest);
  }
}

void
my_hsort_max(int* A, int n)
{
  //second half of the array A[n/2]...A[n-1] elements become leafs
  for(int i=n/2-1; i>=0; i--){
    max_heapify(A, n, i);}

  dump_A(A, 0, n-1);
  // extact element and heapify the remaining array
  for(int i=n-1;i>0; i--){
    swap(&A[0], &A[i]);
    max_heapify(A, i, 0);
  }
}

void
my_hsort_min(int* A, int n)
{
  //second half of the array A[n/2]...A[n-1] elements become leafs
  for(int i=n/2-1; i>=0; i--){
    min_heapify(A, n, i);}

  dump_A(A, 0, n-1);
  // extact element and heapify the remaining array
  for(int i=n-1;i>0; i--){
    swap(&A[0], &A[i]);
    min_heapify(A, i, 0);
  }
}

int main()
{
    alen = sizeof(A)/sizeof(A[0]);
    dump_A(A, 0, alen-1);
    //my_qsort(A, 0, alen-1);
    //my_msort(A, 0, alen-1);
    //my_hsort_max(A, alen);
    my_hsort_min(A, alen);
    dump_A(A, 0, alen-1);
   return 0; 
}
