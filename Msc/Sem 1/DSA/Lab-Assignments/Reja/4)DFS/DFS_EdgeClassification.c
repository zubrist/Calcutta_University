#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	int dfs_no;
	int dfsc_no;
	char color;
	struct node *next;
};

struct edge
{
	int v1;
	int v2;
	struct edge *next;
};

struct edge *tree_edge=NULL,*forward_edge,*back_edge,*cross_edge;
//int visit[n];

int dfs_time=0,dfsc_time=0;

void addvertex(struct node* arr[], int j,int k)
{
	struct node *p,*r;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=k;
	p->color='w';
	p->next=NULL;
	r=arr[j]->next;
	arr[j]->next=p;
	p->next=r;
}

dfs_visit(struct node* arr[], int n, int e, struct node *p)
{
	struct node * r,*q;
	struct edge *t;
	
	dfs_time=dfs_time+1;
	p->dfs_no=dfs_time;
	p->color='g';
	printf("%d ",p->data);
	r=arr[p->data]->next;
	while(r!=NULL)
	{
		q=arr[r->data];
		if (q->color=='w')
		{
			t=(struct edge*)malloc(sizeof(struct edge));
			t->v1=p->data;
			t->v2=r->data;
			t->next=NULL;
			if( tree_edge==NULL)
				tree_edge=t;
			else
			{
				t->next=tree_edge;
				tree_edge=t;
			}
			dfs_visit(arr,n,e,q);
		}
		r=r->next;
	}
	p->color='b';
	dfsc_time=dfsc_time+1;
	p->dfsc_no=dfsc_time;
	
}

void dfs( struct node* arr[], int n, int e)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]->color=='w')
			dfs_visit( arr,n,e,arr[i]);
	}
}

void visit(struct node* arr[], int n, int e)
{
	struct node *p,*q,*r;
	struct edge *t;
	int i,flag;
	
	for(i=1;i<=n;i++)
	{
		p=arr[i];
		q=arr[i]->next;
		while(q!=NULL)
		{
			r=arr[q->data];
			flag=1;
			if((p->dfs_no < r->dfs_no) && (p->dfsc_no > r->dfsc_no))
			{
				t=tree_edge;
				while(t!=NULL)
				{
					if(t->v1==p->data && t->v2== r->data)
						flag=0;
					t=t->next;
				}
				if(flag==1)
				{
					t=(struct edge*)malloc(sizeof(struct edge));
					t->v1=p->data;
					t->v2=r->data;
					t->next=NULL;
					if( forward_edge==NULL)
						forward_edge=t;
					else
					{
						t->next=forward_edge;
						forward_edge=t;
					}
				}
			}
			else if((p->dfs_no > r->dfs_no) && (p->dfsc_no < r->dfsc_no))
			{
				t=(struct edge*)malloc(sizeof(struct edge));
				t->v1=p->data;
				t->v2=r->data;
				t->next=NULL;
				if( back_edge==NULL)
					back_edge=t;
				else
				{
					t->next=back_edge;
					back_edge=t;
				}
			}
			else
			{
				t=(struct edge*)malloc(sizeof(struct edge));
				t->v1=p->data;
				t->v2=r->data;
				t->next=NULL;
				if( cross_edge==NULL)
					cross_edge=t;
				else
				{
					t->next=cross_edge;
					cross_edge=t;
				}
			}
			q=q->next;
		}
	}
}

int main()
{

	int ch;
	int i,j,k,wt,e,n;
	struct node *p,*r;
	struct edge *t;
	
	//input
	printf("MENU:\n1. UNDIRECTED");
	printf("\n2.DIRECTED");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter the number of edges : ");
	scanf("%d",&e);
	struct node *arr[n];
	
	for(i=1;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		r->data=i;
		r->color='w';
		r->next=NULL;
		arr[i]=r;
	}
	
    switch(ch)
    {
		case 1:	// undirected
		    for(i=1;i<=e;i++)
	        {
			    printf("Enter the end vertices of edge e%d : ",i);
  	    		scanf("%d,%d",&j,&k);
           		addvertex(arr,j,k);
           		addvertex(arr,k,j);
	   		}
	   		break;
	   	case 2:	//directed
	   		for(i=1;i<=e;i++)
	        {
			    printf("Enter the end vertices of edge e%d : ",i);
  	    		scanf("%d,%d",&j,&k);
           		addvertex(arr,j,k);
	   		}
	   		break;
	   	default:
	   		printf("Wrong Choice ! Try Again !\n");
	}

	//printing adjacency list
	for(i=1;i<=n;i++)
	{
		printf("\nAdjacency list of node : ");
		p=arr[i];
		while(p!=NULL)
		{
			printf("%d -> ",p->data);
			p=p->next;
		}
		printf("null");
	}
	printf("\n");
	
	//printing dfs traversal
	printf("\nThe DFS Traversal is:\n");
	dfs (arr,n,e);
	visit(arr,n,e);
	
	//printing edge classification
	printf("\n\nThe Tree Edges are: \n");
	t=tree_edge;
	while(t!=NULL)
	{
		printf ("(%d,%d) ",t->v1, t->v2);
		t=t->next;
	}
	printf("\n");
	
	
	printf("\nThe Forward Edges are: \n");
	t=forward_edge;
	while(t!=NULL)
	{
		printf ("(%d,%d) ",t->v1, t->v2);
		t=t->next;
	}
	printf("\n");
	
	printf("\nThe Back Edges are: \n");
	t=back_edge;
	while(t!=NULL)
	{
		printf ("(%d,%d) ",t->v1, t->v2);
		t=t->next;
	}
	printf("\n");
	
	if(ch==2)
	{
	
		printf("\nThe cross Edges are: \n");
		t=cross_edge;
		while(t!=NULL)
		{
			printf ("(%d,%d) ",t->v1, t->v2);
			t=t->next;
		}
		printf("\n");
	}
	
	
	return 0;
}
