#include<stdio.h>

int myBS(int a[],int low,int high)
{
	int mid;
	if (high > low)
	{
    	mid=(low+high)/2;

   		if(mid==a[mid])
       		return mid;
   		else if(mid<a[mid])
       		return myBS(a,low,mid);
	    else
	        return myBS(a,mid+1,high);
	}
	else
	    return -1;
}

int main(){
	int i,j=0,n;
	int a[30];
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter elements in the array: ");
	for (i=0;i<n;i++)
	    scanf("%d",&a[i]);
	j=myBS(a,0,n-1);
	if(j==-1)
	     printf("No Index present for which array[index] = index\n");
	else
	     printf("Index for which array[index] = index is : %d\n",j);
	return 0;
}
