#include<stdio.h>

int a,b,u,v,n,i,j,ne=1;
int parent[10]={0},min,mincost=0,cost[10][10];

int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int check(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

void main()
 
{
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix:\n");
 
	for(i=1;i<=n;i++)
 	{
		for(j=1;j<=n;j++)
 		{
			scanf("%d",&cost[i][j]);
 			if(cost[i][j]==0)
				cost[i][j]=999;
		}
 	}

	while(ne < n)
 	{
 		for(i=1,min=999;i<=n;i++)
		{
	 		for(j=1;j<=n;j++)
			{
 				if(cost[i][j]< min)
 				
 				{
 					min=cost[i][j];
 					a=u=i;
					b=v=j;
 				}
 			}
		}
		
		u = find(u);
		v = find(v);

		if(check(u,v))
		{
			printf("edge %d -  (%d,%d) Cost =%d\n",ne++,a,b,min);
			mincost +=min;
		}

 		cost[a][b]=cost[b][a]=999;
 
	}
 
	printf("\nMinimun cost=%d\n",mincost);
 
 
}


/*
//INPUT////
///////////
0 3 1 6 0 0 
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0


0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/

