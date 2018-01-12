#include<stdio.h>
int n,i,j,k,t;
int check(int s[],int p)
{  
	int ptr=0;
    for(int i=0;i<n;i++)
    {
		if(s[i]==p)
        	ptr++;
    }           
        if(ptr==0)
            return 1;
        else
            return 0; 
}    
                      
int main()
{   
	printf("enter the no of jobs: ");
	scanf("%d",&n);
	int slot[n],profit,p[n],d[n];
	for(i=0;i<n;i++)
	{
		printf("enter the profit of job: ");
		scanf("%d",&p[i]);                  
		printf("enter the deadline of job: ");
		scanf("%d",&d[i]); 
	}       
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i]<p[j])
			{ 
				t=p[i];
				p[i]=p[j];
				p[j]=t;
				t=d[i];
				d[i]=d[j];
				d[j]=t;              
			}
		}
	}
	for(i=0;i<n;i++)
		slot[i]=0;                        
	for(i=0;i<n;i++)
		for(j=d[i];j>0;j--)
		{
			if(check(slot,j)==1)
			{
				slot[i]=j;
				break;
			}  
		}
	int maxprofit=0;       
	for(i=0;i<n;i++)
	{
			if(slot[i]>0){
				printf("%d\t%d\t%d\n",i+1,p[i],d[i]);
				maxprofit=maxprofit+p[i];
			}
	}
	printf("\nmaximum profit is %d\n",maxprofit);
}   
