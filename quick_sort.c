#include<stdio.h>

int partition (int a[], int low, int high)
{
    	int pivot, i, j, temp;
	
		pivot = a[low];
		i = low;
		j = high+1;
		while(i <= j) {
			do{
				i++;
			  }while(pivot >= a[i]);
			do{
				j--;
			  }while(pivot < a[j]);
	
			if(i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[j];
		a[j] = a[low];
		a[low] = temp;
		return j;

}

void quickSort(int a[], int low, int high)
{
    if (low <= high)
    {
        
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main()
{
	int i,j,n,a[30];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quickSort(a, 0, n-1);
	printf("Sorted aray: \n");
    for (i = 0; i < n; i++)
    {
    	printf("%d ",a[i]);
    }
	printf("\n");
	return 0;
}





