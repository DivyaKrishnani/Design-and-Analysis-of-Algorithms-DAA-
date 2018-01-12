#include<stdio.h>
#define MAX 99999;

int main(){
	int p[30],n,k,i,j,len,temp;

	printf("Enter no. of instances : ");
	scanf("%d",&n);

	printf("Enter the instances\n");
    for (k = 0; k < n; k++)
    	scanf("%d",&p[k]);
    
	int m[n][n],r[n][n];
	for (k = 0; k < n; k++){
		m[k][k]=0;
		r[k][k] = 0;
	}
	for(len=1;len<n-1;len++)
	{
		for(i=1;i<n-len;i++)
		{
			j=i+len;
			m[i][j] = MAX;
			for(k=i;k<j;k++)
			{
				temp = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(temp < m[i][j]){
					m[i][j]=temp;
					r[i][j] = k;					
				}
			}
			printf("m[%d][%d]: %d \t min k: %d\n",i,j,m[i][j],r[i][j]);
		}
		printf("\n");
	}
	

	printf("Optimal no. of scalar multiplications needed: %d\n",m[1][n-1]);
	return 0;
}

/*
5 4 6 2 7


*/

