#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define INFINITE 999

int graph[INFINITE][INFINITE];
int span_wght[INFINITE][INFINITE];
int source;
int eMin,eMax,seed;
int n,ed,f,r;

struct Sort{
	int v1,v2;
	int weight;
}que[INFINITE];

int cycle(int s,int d){
	int j,k;
	if(source==d)
		return 1;
	for(j=0;j<n;j++)
		if(span_wght[d][j]!=INFINITE && s!=j) {
			if(cycle(d,j))
				return 1;
		}
		return 0;
}
void build_tree(){
	int i,j,w,k,count=0;
	for(count=0;count<n;f++){
		i=que[f].v1;
		j=que[f].v2;
		w=que[f].weight;
		span_wght[i][j]=span_wght[j][i]=w;
		source=i;
		k=cycle(i,j);
		if(k)
			span_wght[i][j]=span_wght[j][i]=INFINITE;
		else
			count++;
	}
}
void swap(int *i,int *j){
	int t;
	t=*i;
	*i=*j;
	*j=t;
}
void main()
{
	int i,j,k=0,temp;
	int minCost=0;

	printf("\n\n\tKRUSKAL'S ALGORITHM TO FIND SPANNING TREE 1 \n\n");
	printf("Enter the number of vertices of graph. \n");
	scanf("%d",&n);
	printf("Enter the seed value. \n");
	scanf("%d",&seed);
	printf("Enter the minimum of edge weight. \n");
	scanf("%d",&eMin);
	printf("Enter the maximum of edge weight. \n");
	scanf("%d",&eMax);
	srand(seed);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j]=INFINITE;
			span_wght[i][j]=INFINITE;
		}
	}

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			graph[i][j]=graph[j][i]=rand()%(eMax-eMin)+eMin;
			if(i==j){
				graph[i][j]=0;
			}
			que[r].v1=i;
			que[r].v2=j;
			que[r].weight=graph[i][j];
			if(r){
				for(k=0;k<r;k++)
					if(que[k].weight>que[r].weight){
						swap(&que[k].weight,&que[r].weight);
						swap(&que[k].v1,&que[r].v1);
						swap(&que[k].v2,&que[r].v2);
					}
			}
			r++;
		}
		printf("\n The input adjacency matrix is\n\n");
		for(i=0;i<n;i++,printf("\n"))
			for(j=0;j<n;j++)
				printf("%4d",graph[i][j]);
		build_tree();

		printf("\nThe edges of minimum spanning tree are\n\n");
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(span_wght[i][j]!=INFINITE){
					printf(" <%d , %d , %d> \n",i,j,span_wght[i][j]);
					minCost+=span_wght[i][j];
				}
				printf("\n\tMinimum cost : %d\n\n\n ",minCost);
				system("pause");
}