#include<stdio.h>
#include<math.h>
void main()
{
	int num[20],ti[50],ci[50],ai[50],n,i,c,j,p;
	printf("\n Enter the no. of digits:");
	scanf("\n %d",&n);
	for(i=0;i<n;i++)
		num[i]=0;
	printf("number \tti  \tci  \tai",ti[c],ci[c],ai[c]);
	printf("\n---------------------------");
	c=1;
	ci[0]=0;
	p=(int)pow(2,n);
	while(c<=p)
	{
		ti[c]=0;
		ci[c]=0;
		ai[c]=0;
		i=n-1;
		while(i>=0)
		{
			if(num[i]==1)
			{
				num[i]=0;
				ti[c]=ti[c]+1;//calculate number of changes
			}
			else if(num[i]==0)
			{
				num[i]=1;
				ti[c]=ti[c]+1;//calculate number of changes
				break;	
			}
			i--;	
		}
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d",num[j]);
			if(num[j]==1)
				ci[c]=ci[c]+1;//calculate number of 1's
		}
		ai[c]=ti[c]+ci[c]-ci[c-1];//Calculating amortized cost
		printf("\t%d  \t%d  \t%d",ti[c],ci[c],ai[c]);
		c++;	
			
	}	
}
