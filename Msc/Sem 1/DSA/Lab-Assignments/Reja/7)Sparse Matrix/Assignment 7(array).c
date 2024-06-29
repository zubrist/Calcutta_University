#include <stdio.h>  
int main()  
{  
	int i,j,temp; 
    int sparse_matrix[20][20] ;
    int m,n;
    printf("\nEnter the number of rows and columns of the matrix: ");
    scanf("%d,%d",&m,&n);
    for(i=1;i<=m;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		printf("\nEnter the %d,%d th element: ",i,j);
    		scanf("%d",&sparse_matrix[i][j]);
    	}
    }
   // size of matrix  
    int size = 0;  
    for(i=1; i<=m; i++)  
    {  
        for(j=1; j<=n; j++)  
        {  
            if(sparse_matrix[i][j]!=0)  
            {  
                size++;  
            }  
        }  
    }  
    if(size<=(m*n)/3)
    {
 		  // Defining final matrix  
    	int matrix[size+1][3];   
     	int k=1;  
   		// Computing final matrix
		printf("\n");
		printf("size = %d\n\n",size+1);
    	for(i=1;i<=m;i++)  
    	{	  
        	for(j=1;j<=n;j++)  
        	{  
            	if(sparse_matrix[i][j]!=0)  
            	{  
                	matrix[k][1] = i;  
                	matrix[k][2] = j;  
                	matrix[k][3] = sparse_matrix[i][j];
            		k=k+1;
            	}  
      		}  
    	}  
   // Displaying the final matrix 
  		printf("\nTranspose representation in 2D Matrix...\n");
		for(i=1;i<=m;i++)
   		{
    		for(j=1;j<=n;j++)
    		{
    			printf("%d ", sparse_matrix[j][i]);  
            	printf("\t");  
    		}
    		printf("\n");
   		 }
   		printf("\nThe Sparse Matrix representation of the given matrix is:  \n");
   		matrix[0][1]=m;
		matrix[0][2]=n;
		matrix[0][3]=size; 
		printf("row\t column\t value\n") ;
    	for(i=0 ;i<=size; i++)  
    	{  
        	for(j=1; j<=3; j++)  
        	{  
            	printf("%d ", matrix[i][j]);  
            	printf("\t");  
        	}  
        	printf("\n");  
    	}  
    	int transpose[size+1][3];
    	transpose[0][1]=matrix[0][1];
    	transpose[0][2]=matrix[0][2];
    	transpose[0][3]=matrix[0][3];
    	for(i=1 ;i<=size; i++)  
    	{  
       		for(j=1; j<=3; j++)  
        	{  
           		transpose[i][1]=matrix[i][2];
            	transpose[i][2]=matrix[i][1];
            	transpose[i][3]=matrix[i][3];
        	}  
        	printf("\n");  
    	} 
    	for(i=1 ;i<=size; i++)  
    	{ 
       		for(k=i+1;k<=size;k++)
        	{
        		//	printf("\ntranspose[i][1]=%d\ntranspose[k][1]=%d",transpose[i][1],transpose[k][1]);
           		if(transpose[i][1]>transpose[k][1])
           		{
           			temp=transpose[i][1];
           			transpose[i][1]=transpose[k][1];
           			transpose[k][1]=temp;
           			temp=transpose[i][2];
           			transpose[i][2]=transpose[k][2];
           			transpose[k][2]=temp;
           			temp=transpose[i][3];
           			transpose[i][3]=transpose[k][3];
           			transpose[k][3]=temp;
           		}
			}  
    	} 
    	printf("\nTranspose representation using 3 tuple form....\n");
    	printf("row\tcolumn\tvalue\n") ;
    	for(i=0 ;i<=size; i++)  
    	{  
        	for(j=1; j<=3; j++)  
        	{  
            	printf("%d ", transpose[i][j]);  
            	printf("\t");  
        	}  
        	printf("\n");  
    	}
	}
	else
		printf("\nThe matrix is not a sparse matrix.\n");
    return 0;  
}
