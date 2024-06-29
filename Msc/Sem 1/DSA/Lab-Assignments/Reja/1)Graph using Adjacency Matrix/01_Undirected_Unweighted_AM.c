#include <stdio.h>
#include <stdlib.h>
int adj_mat[10][10];
int n;

int input() {
	int i,j,s,e;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	printf("Therefore the no. of nodes are: ");
	for(i=0;i<n;i++) { //Displaying name of nodes
		printf("%d\t",i);
	}
	for(i=0;i<n;i++) { //Filling matrix with zeroes
		for(j=0;j<n;j++) {
			adj_mat[i][j] = 0;
		}
	}
	while(s!=-999||e!=-999) {
		printf("\nEnter the connections: (Enter -999 to stop))");
		printf("\nEnter starting node: ");
		scanf("%d",&s);
		printf("\nEnter ending node: ");
		scanf("%d",&e);
		if (s != -999 || e != -999) {
			adj_mat[s][e] = 1;
			adj_mat[e][s] = 1;
		}
	}
}

int display() {
	int i,j;
	printf("Adjacency matrix representation of the undirected unweighted graph is: \n");
	for(i=0;i<n;i++) { 
		for(j=0;j<n;j++) {
			printf("%d\t",adj_mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	input();
	display();
}
