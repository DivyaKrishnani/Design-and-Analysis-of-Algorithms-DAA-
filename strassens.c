#include<stdio.h>

int main(){
	int x[2][2],y[2][2],z[2][2];

	int i,j;

	printf("enter first matrix\n");

	for(i=0;i<2;i++)
	    for(j=0;j<2;j++)
	        scanf("%d",&y[i][j]);

	printf("enter second matrix\n");
	for(i=0;i<2;i++)
	    for(j=0;j<2;j++)
	        scanf("%d",&z[i][j]);

	printf("\n");
	
	printf("First matrix is\n");
	for(i=0;i<2;i++)
	{
	    printf("\n");
	    for(j=0;j<2;j++)
	        printf("%d\t",y[i][j]);
    }

	printf("\nSecond matrix is\n");
	for(i=0;i<2;i++)
    {
	    printf("\n");
	    for(j=0;j<2;j++)
	        printf("%d\t",z[i][j]);
    }
	printf("\n");

	int a,b,c,d,e,f,g;

	a = (y[0][0]+y[1][1])*(z[0][0]+z[1][1]);
	b = (y[1][0]+y[1][1])*z[0][0];
	c = y[0][0] * (z[0][1]-z[1][1]);
	d = y[1][1] * (z[1][0]-z[0][0]);
	e = (y[0][0] + y[0][1]) * z[1][1];
	f = (y[1][0] - y[0][0]) * (z[0][0]+z[0][1]);
	g = (y[0][1] - y[1][1]) * (z[1][0]+z[1][1]);

	x[0][0]=a+d-e+g;
	x[0][1]=c+e;
	x[1][0]=b+d;
	x[1][1]=a+c-b+f;

	printf("Resultant matrix is\n");
	for(i=0;i<2;i++)
    {
	    printf("\n");
	    for(j=0;j<2;j++)
	        printf("%d\t",x[i][j]);
    }
	printf("\n");
	return 0;
}



