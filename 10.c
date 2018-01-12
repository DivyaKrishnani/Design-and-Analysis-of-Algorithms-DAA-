#include<stdio.h>

int main(){
	int a[30],i,n,j,flag=0;
    printf("enter no. of  elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");    
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

	
    for(i=0;i<n;i++){
    	for(j=i+1;j<n;j++){
    		if(a[i]==a[j]){
    			printf("First repeating element is %d\n",a[i]);
    			flag=1;
    			break;
    		}
    	}
    	if(flag==1)
    		break;
    }
    if(flag==0)
    	printf("No repeated element present\n");
    return 0;
}
