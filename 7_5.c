#include<stdio.h>

#include "myheader.h"
#define MAX 100

int main(){
	int a[MAX],c[MAX],i,n,ans=0;
    printf("enter no. of  elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
		
    }
    for(i=0;i<MAX;i++)
		c[i]=0;

	mergesort(a,0,n-1); 
	int k=a[n-1]+1;
	for(i=0;i<n;i++)
		c[a[i]%k] += k;

	int max=a[0];
	for(i=0;i<MAX;i++)
	{
		if(c[i]>max){
			max=c[i];
			ans=i;
		}	

	}
	

	printf("Element occuring max times is %d \n",ans);

	return 0;
}
