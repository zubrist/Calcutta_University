#include<stdio.h>
struct poly
{
	int coeff;
	int expo;
}p1[20],p2[20],p3[40];

int read(struct poly[]);
int add(int);
int mul();
int diff(struct poly[], int);
void display(struct poly[],int);

int t1,t2,t3;

int main()
{
	int g=0,f,ch;
	do
	{
		if(g==0)
		{
			printf("\n Entering Polynomial-1 (NOTE: Please enter the terms in descending order of their exponent)");
			printf("\n-----------------------");
			t1=read(p1);
			printf("\n Polynomial-1:");
			display(p1,t1);
			printf("\n Entering Polynomial-2 (NOTE: Please enter the terms in descending order of their exponent)");
			printf("\n-----------------------");
			t2=read(p2);
			printf("\n Polynomial-2:");
			display(p2,t2);
		}
		
		printf("\n The MENU for polynomial operations:");
		printf("\n 1-Addition of the two polynomials");
		printf("\n 2-Subtraction of the 2nd polynomial from the 1st polynomial");
		printf("\n 3-Multiplication of both the polynomials");
		printf("\n 4-Differentiation of both the polynomials");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				t3=add(1);
				printf("\n Resultant Polynomial:");
				display(p3,t3);
				break;
			case 2:
				t3=add(0);
				printf("\n Resultant Polynomial:");
				display(p3,t3);
				break;
			case 3:
				t3=mul();
				printf("\n Resultant Polynomial:");
				display(p3,t3);
				break;
			case 4:
				t3=diff(p1,t1);
				printf("\n Result after differentiating 1st Polynomial:");
				display(p3,t3);
				t3=diff(p2,t2);
				printf("\n Result after differentiating 2nd Polynomial:");
				display(p3,t3);
				break;	
					
					
			default:
				printf("\n You have entered wrong choice!!");
					
		}
		printf("\n Do you wish to continue? Enter 1 for YES, 0 for NO:");
		scanf("%d",&f);
		if(f==1)
		{
			printf("\n Do you want to continue with the same polynomials? Enter 1 for YES, 0 for NO:");
			scanf("%d",&g);
		}
	}while(f==1);
	
	printf("\n Thank you for using our program!!");
	return 0;
}
int read(struct poly p[20])
{
	int t,i;
	printf("\n Enter the number of terms:");
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("\n Enter the coefficient of term-%d:",i+1);
			scanf("%d",&p[i].coeff);
			printf("\n Enter the power of term-%d:",i+1);
			scanf("%d",&p[i].expo);
	}
	return t;
}
void display(struct poly p[20], int t)
{
	int i;
	printf(" %dx^%d  ",p[i].coeff,p[i].expo);
	for(i=1;i<t-1;i++)
	{
		if(p[i].coeff==0)
			continue;
		printf(" + %dx^%d  ",p[i].coeff,p[i].expo);
	}
	if(p[i].coeff!=0)
		printf(" +  %dx^%d  ",p[i].coeff,p[i].expo);
}
int add(int x)
{
	int i=0, j=0, k=0;
	while(i<t1 && j<t2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			if(x==1)
				p3[k].coeff=p1[i].coeff + p2[j].coeff;
			if(x==0)
				p3[k].coeff=p1[i].coeff + (-1)*p2[j].coeff;	
			p3[k].expo=p1[i].expo;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].expo=p1[i].expo;
			k++;
			i++;
			
		}
		else if(p2[i].expo>p1[j].expo)
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].expo=p2[j].expo;
			k++;
			j++;
			
		}
	}
	while(i<t1)
	{
	
		p3[k].coeff=p1[i].coeff;
		p3[k].coeff= p1[i].coeff;	
		p3[k].expo=p1[i].expo;
		k++;
		i++;
			
	}
	while(j<t2)
	{
		if(x==1)
			p3[k].coeff=p2[j].coeff;
		if(x==0)
			p3[k].coeff=(-1)*p2[j].coeff;	
		p3[k].expo=p2[j].expo;
		k++;
		j++;	
	}
	
	return k;
}
int mul()
{
	int i,j,k=0,p;
	for(i=0;i<t1;i++)
	{
		for(j=0;j<t2;j++)
		{
			p3[k].coeff=p1[i].coeff * p2[j].coeff;
			p3[k].expo=p1[i].expo + p2[j].expo;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(p3[i].expo==p3[j].expo)
			{
				p3[i].coeff=p3[i].coeff+p3[j].coeff;
				for(p=j;p<k-1;p++)
				{
					p3[p]=p3[p+1];
				}
				k--;
			}
		}
	}
	//printf("\n %d",k);
	return k;
}
int diff(struct poly pol[],int l)
{
	int i,k=0;
	for(i=0;i<l;i++)
	{
		p3[k].coeff=pol[i].coeff * pol[i].expo;
		p3[k].expo=pol[i].expo -1;
		k++;
	}
	return k;
}
