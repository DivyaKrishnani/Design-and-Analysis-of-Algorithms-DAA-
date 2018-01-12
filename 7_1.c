#include <stdio.h>

#include "myheader.h"

int two_elements(int a[], int n, int k)
{
    int l=0, h=n-1;
    while (l < h)
    {
         if(a[l] + a[h] == k)
         {
			printf("%d and %d sum upto %d(k)\n",a[l],a[h],k);
         	return 1; 
         }
         else if(a[l] + a[h] < k)
              l++;
         else
              h--;
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
    printf("Enter K to find whether there are two elements in the array such that their sum is equal to K: ");
    scanf("%d",&k);
	mergesort(a, 0, n-1);

    if(two_elements(a,n,k))
        printf("Array has two elements whose sum = k\n");
    else
        printf("Array doesnot have two elements whose sum = k\n");
    return 0;
}
