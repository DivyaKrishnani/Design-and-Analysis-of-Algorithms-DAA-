#include <stdio.h>

#include "myheader.h"

int three_elements(int a[], int n, int k)
{
	
	int l,h,i;
	for(i=0;i<n;i++){
		l=i+1;
		h=n-1;
		while(l<h)
		{
			if(a[l]+a[h]+a[i] == k)
			{
				printf("%d + %d + %d = %d(k)\n",a[i],a[l],a[h],k);		
				return 1;
			}	

			else if(a[l]+a[h]+a[i] < k)
				l++;

			else
				h--; 

		}
	}
    return 0;
}

int main()
{
    int a[30], i,n,k;
    printf("enter no. of  elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter K to find whether there are three elements in the array such that their sum is equal to K: ");
    scanf("%d",&k);
	mergesort(a, 0, n-1);
    if(three_elements(a,n,k))
        printf("Array has three elements whose sum = k\n");
    else
        printf("Array doesnot have three elements whose sum = k\n");
    return 0;
}


/*
23 1 55 33 12 65 9 2
 -- k=90
*/
