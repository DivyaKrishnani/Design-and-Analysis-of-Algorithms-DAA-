
void merge(int *a, int low, int high, int mid)
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


void mergesort(int *a, int low, int high)
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


int binarysearch(int arr[], int l, int r, int x)
{
   if (r > l)
   {
        int mid = l + (r - l)/2;
 
        if (arr[mid] == x)  
        	return mid;
 
        
        if (arr[mid] > x) 
        	return binarysearch(arr, l, mid-1, x);
 
        else
        	return binarysearch(arr, mid+1, r, x);
   }
 
   
   return -1;
}
