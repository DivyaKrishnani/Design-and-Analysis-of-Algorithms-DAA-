#include<stdio.h>

int BinarySearch(int a[],int low,int high,int x)
{
	int mid;
	if (high >= low)
	{
    	mid=(low+high)/2;
    	if(x==a[mid])
        	return mid;
            
    	else if(x<a[mid])
        	return BinarySearch(a,low,mid,x);
    	else
        	return BinarySearch(a,mid+1,high,x);
	}
	else
    	return -1;
}

int main(){
	int i,j,n;
	int a[30];
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter elements in the array: ");
	for (i=0;i<n;i++)
	    scanf("%d",&a[i]);

	int element;

	printf("Enter elements to search for: ");
	scanf("%d",&element);
	
	j=BinarySearch(a,0,n-1,element);

	if(j==-1)
	    printf("Element not found\n");
	else
	    printf("Element found at position- %d\n",j+1);
	return 0;
}
