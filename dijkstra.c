#include<stdio.h>
#define INFINITY 999
#define MAX 10

void dijikstra(int G[MAX][MAX], int n, int source)
{
	int cost[MAX][MAX], w[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		w[i]=cost[source][i];
		pred[i]=source;
		visited[i]=0;
	}
	w[source]=0;
	visited[source]=1;
	count=1;
	
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(w[i] < mindistance && !visited[i])
			{
				mindistance=w[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < w[i])
				{
					w[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=source)
		{
			printf("\nDistance of %d = %d", i, w[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=source);
		}
}
 

void main(){
	int G[MAX][MAX], i, j, n, u;
	
	printf("Enter the no. of vertices:: ");
	scanf("%d", &n);
	printf("Enter the adjacency cost matrix::\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d", &G[i][j]);
	printf("Enter the starting node:: ");
	scanf("%d", &u);
	dijikstra(G,n,u);
	printf("\n");
}


/*

0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

////////////////////

0 1 1 1 
1 0 1 0
1 1 0 1
1 0 1 0

*/
