#include <stdio.h>
#include <conio.h>

//global veriable
int i, n, j, k;

//prototype declaration
void printArray(int [], int );
void heapSort(int [], int );
void hepify(int [], int);
void swap(int*, int*);

int main() {
	
	int n;
	
	printf("Enter the no of element: ");
	scanf("%d", &n);

	int arr[n];
	
	printf("Enter element: ");
	
	for(i=1; i<=n; i++) {
		scanf("%d", &arr[i]);
		hepify(arr, i);
	}
	
	//printArray(arr, n);
	
	printf("\n");
	
	heapSort(arr, n);

	printArray(arr, n);

	return 0;
}

//printArray 

void printArray(int arr[], int n) {
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		printf("%d ",arr[i]);
	}
}

//heapSort
void heapSort(int arr[], int n) {
	
	
	printf("\nmax heap : \n");
	printArray(arr, n);
	
	for (i = n; i >= 1; i--) {
		
		swap(&arr[i], &arr[1]);
		
		for (k = i-1; k >= 1; k--)
			hepify(arr, k);	
	}

	
}

//heapify
void hepify(int arr[], int i) {
	
	for(j = 1; j <= i; j++) {
	int child = i; 

	int parent = child/2;

	while(parent >= 1) {
		
		if(parent != 1) {
			if (arr[parent] < arr[child])	{
				swap(&arr[parent], &arr[child]);
			}	
			child = parent; 
			parent = child/2; 
		} else {
			if (arr[parent] < arr[child])	{
				swap(&arr[parent], &arr[child]);
			}
			break;
		}
		
	}
	
}
	
}

//swap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
