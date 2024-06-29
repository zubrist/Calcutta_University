#include<stdio.h>
int n;
int sieve(int b[][20], int a[],int y)
{
	int i,j,k=1,subtree=1,f,flag=1;
	b[0][0]=a[0];
	while(k<n)
	{
		i=0;
		f=0;
		while(i<subtree && f!=1)
		{
			j=0;
			if(b[i][0]>a[k])
			{
				while(b[i][j]!=' ')
					j++;
				b[i][j]=a[k];
				f=1;
			}
			i++;
		}
		if(f==0)
		{
			subtree++;
			b[i][0]=a[k];
		}
		k++;
	}
	f=0;
	for(i=0;i<subtree;i++)
	{	
		k=0;
		while(b[i][k]!=' ')
			k++;
			for(j=k-1;j>=0;j--)
				a[f++]=b[i][j];
			printf("SUBLIST- %d : ",i+1);
			for(j=0;j<k;j++)
			{
				if(y==0)
					printf("%d ",b[i][j]);
				else
					printf("%d ",b[i][k-j-1]);
			}
			printf("\n");
	}
	printf("\n");
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			flag=0;
			break;
		}
	}
	return(flag);
}
void main()
{
	int a[20],b[20][20],i,j,k,t,x=0;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	i=0;
	while(x!=1)
	{ 
		printf("\nPASS- %d\n",i+1);
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
				b[j][k]=' ';
		}
		if(i%2==0)
			x=sieve(b,a,0);
		else
			x=sieve(b,a,1);	
		i++;
	}
	printf("\nSORTED ELEMENTS ARE :\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}


