#include <stdio.h>
#include <unistd.h>

void main(){
	
	int i,j,a,b,c,v,e,ch,sw,cost;
	int arr[50][50];
	int costArr[50][50];
	
	while(1){
		
		printf("Enter the number of vertices : ");
		scanf("%d",&v);
		printf("Enter the number of edges : ");
		scanf("%d",&e);
		if((v<=1 || v>=50) && (e<=1 || e>=50)){
			printf("Enter valid number of vertices. exiting program........");
				exit(0);
		}
		
		else{
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
				arr[i][j]=0;
				costArr[i][j]=0;
				}
			}
		}
	
			
		printf(" Press 1 for an undirected & unweighted graph,\n Press 2 for an directed & unweighted graph,\n");
		printf(" Press 3 for an undirected & weighted graph,\n Press 4 for an directed & weighted graph, \n Else Press any key to exit.\n\n");
		printf("Please enter your CHOICE:  ");
		scanf("%d",&sw);
		ch=1;
		switch(sw){
			case 1:
			while(ch==1){
				printf("Enter the source vertex within 0 and %d: ",v-1);
				scanf("%d",&a);
				printf("Enter the destination vertex 0 and %d: ",v-1);
				scanf("%d",&b);
				printf("Enter the edge between them:");
				scanf("%d",&c);
				if((a>=0 && a<v) && (b>=0 && b<v) && (c>=0 && c<e))
					arr[a][c]=arr[b][c]=1;
				else{
					printf("Please enter valid set of edges. Exiting program.......");
					exit(0);
				}
				printf("To insert any other connections press 1, else press any key to exit.");
				scanf("%d",&ch);
				}
			
			printf("\n--------------THE INCEDENCE MATRIX OF THE GIVEN GRAPH IS ---------------------\n\n");
			
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
					if (i==0){
						if (j>0)
						printf("| E%d ",j);
						else
						printf("     ");
					}
					else if((i!=0) && (j==0)){ 
					printf("| V%d |",i-1);	
					}
					else
					printf("  %d  ",arr[i-1][j-1]);
				}
				printf("\n");
			}
			break;
			
			case 2:
			while(ch==1){
				printf("Enter the source vertex within 0 and %d: ",v-1);
				scanf("%d",&a);
				printf("Enter the destination vertex 0 and %d: ",v-1);
				scanf("%d",&b);
				printf("Enter the Connected edge ");
				scanf("%d",&c);
				if((a>=0 && a<v) && (b>=0 && b<v) && (c>=0 && c<e)){
					arr[a][c]=1;
					arr[b][c]=-1;
				}
				else{
					printf("%d , %d, %d, %d, %d ", a, v, b , c , e);
					printf("Please enter valid set of edges      . Exiting program.......");
					exit(0);
				}
				printf("To insert any other connections press 1, else press any key to exit.");
				scanf("%d",&ch);
				}
			printf("\n--------------THE INCEDENCE MATRIX OF THE GIVEN GRAPH IS ---------------------\n\n");
			
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
					if (i==0){
						if (j>0)
						printf("| E%d ",j);
						else
						printf("     ");
					}
					else if((i!=0) && (j==0)){ 
					printf("|  V%d |",i-1);	
					}
					else
					printf("  %d  ",arr[i-1][j-1]);
				}
				printf("\n");
			}
			break;
			
			case 3:
			while(ch==1){
				printf("Enter the source vertex within 0 and %d: ",v-1);
				scanf("%d",&a);
				printf("Enter the destination vertex 0 and %d: ",v-1);
				scanf("%d",&b);
				printf("Enter the Connected edge ");
				scanf("%d",&c);
				printf("Enter the Cost of the edge entered: ");
				scanf("%d",&cost);
				if((a>=0 && a<v) && (b>=0 && b<v) && (c>=0 && c<e)){
					arr[a][c]=arr[b][c]=1;
					costArr[a][c]=costArr[b][c]=cost;
				}
				else{
					printf("Please enter valid set of edges. Exiting program.......");
					exit(0);
				}	
				printf("To insert any other connections press 1, else press any key to exit.");
				scanf("%d",&ch);
				}
				
			printf("\n--------------THE INCEDENCE MATRIX OF THE GIVEN GRAPH IS ---------------------\n\n");
			
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
					if (i==0){
						if (j>0)
						printf("| E%d ",j);
						else
						printf("     ");
					}
					else if((i!=0) && (j==0)){ 
					printf("|  V%d |",i-1);	
					}
					else
					printf("  %d  ",arr[i-1][j-1]);
				}
				printf("\n");
			}
			printf("\n--------------THE COST MATRIX OF THE GIVEN GRAPH IS ---------------------\n\n");
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
					if (i==0){
						if (j>0)
						printf("| E%d ",j);
						else
						printf("     ");
					}
					else if((i!=0) && (j==0)){ 
					printf("|  V%d |",i-1);	
					}
					else
					printf("  %d  ",costArr[i-1][j-1]);
				}
				printf("\n");
			}
			break;
			
			case 4:
			while(ch==1){
				printf("Enter the source vertex within 0 and %d: ",v-1);
				scanf("%d",&a);
				printf("Enter the destination vertex 0 and %d: ",v-1);
				scanf("%d",&b);
				printf("Enter the Connected edge ");
				scanf("%d",&c);
				printf("Enter the Cost of the edge entered: ");
				scanf("%d",&cost);
				if((a>=0 && a<v) && (b>=0 && b<v) && (c>=0 && c<e)){
					arr[a][c]=1;
					arr[b][c]=-1;
					costArr[a][c]=cost;
				}
				else{
					printf("Please enter valid set of edges. Exiting program.......");
					exit(0);
				}
					
				printf("To insert any other connections press 1, else press any key to exit.");
				scanf("%d",&ch);
				}
				
			printf("\n--------------THE INCEDENCE MATRIX OF THE GIVEN GRAPH IS ---------------------\n\n");
			
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
					if (i==0){
						if (j>0)
						printf("| E%d ",j);
						else
						printf("     ");
					}
					else if((i!=0) && (j==0)){ 
					printf("|  V%d |",i-1);	
					}
					else
					printf("  %d  ",arr[i-1][j-1]);
				}
				printf("\n");
			}
			printf("\n--------------THE COST MATRIX OF THE GIVEN GRAPH IS ---------------------\n\n");
			for (i=0;i<=v;i++){
				for (j=0;j<=e;j++){
					if (i==0){
						if (j>0)
						printf("| E%d ",j);
						else
						printf("     ");
					}
					else if((i!=0) && (j==0)){ 
					printf("|  V%d |",i-1);	
					}
					else
					printf("  %d  ",costArr[i-1][j-1]);
				}
				printf("\n");
			}
			break; 
			
			default:
				printf("Exiting Program.........");
				exit(0);
			
		}
	
	}
}