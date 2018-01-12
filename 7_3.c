#include<stdio.h>

#include "myheader.h"


int main(){
	int a[30],b[30],i,n1,n2,flag=-1,k,val;
    printf("enter no. of elements in first array\n");
    scanf("%d",&n1);
    printf("enter the elements\n");    
    for (i = 0; i < n1; i++)
        scanf("%d",&a[i]);
    
	printf("enter no. of elements in second array\n");
    scanf("%d",&n2);
    printf("enter the elements\n");    
    for (i = 0; i < n2; i++)
        scanf("%d",&b[i]);
    printf("Enter K such that there exists a ∈ A, b ∈ B such that a + b = K: ");
    scanf("%d",&k);
   	mergesort(a,0,n1-1);
	
	for(i=0;i<n2;i++)
	{
		val = k-b[i];
		flag = binarysearch(a,0,n1-1,val);
		if(flag != -1)	
			break;	
	}

	if (flag != -1)
		printf("There exists a ∈ A, b ∈ B such that a + b = K\n");
	else
		printf("Does not exists\n");	

	return 0;
}

/*
enter no. of elements in first array
5
enter the elements
3 2 17 15 10
enter no. of elements in second array
4
enter the elements
12 3 11 8
Enter K such that there exists a ∈ A, b ∈ B such that a + b = K: 18
There exists a ∈ A, b ∈ B such that a + b = K
*/
