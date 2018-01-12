#include<stdio.h>

#include "myheader.h"

int main(){
	int a[30],i,n,flag=0;
    printf("enter no. of  elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
   
	mergesort(a,0,n-1);   //Sorting array with (nlogn) time complexity

	for(i=0;i<n-1;i++){
		if(a[i] == a[i+1]){
			flag=1;

		}
	}

	if(flag==1){
		printf("Duplicate elements present in array\n");
	}	

	else{
		printf("No dulicate elements found\n");
	}	

	
}
