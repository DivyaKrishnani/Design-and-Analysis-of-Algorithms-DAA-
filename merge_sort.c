#include <stdio.h>

void merge(int a[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

int main()
{
    int a[20], i,n;
    printf("enter no.  the elements\n");
	scanf("%d",&n);
	printf("Enter elements in the array: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a, 0, n-1);
       printf("sorted array\n");
    for (i = 0; i < n; i++)
    {
           printf("%d ",a[i]);
    }
	printf("\n");
    return 0;
}

