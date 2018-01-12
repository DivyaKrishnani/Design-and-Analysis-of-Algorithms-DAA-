#include<stdio.h>

int main(){
	int m,n,i,j,pi[30];
	float p[30],w[30],p_w[30],x[30],max=0;

	printf("Enter knapsack capacity: ");
	scanf("%d",&m);

	printf("Enter no. of problems: ");
	scanf("%d",&n);

	printf("Enter profits and coressponding weights\n");
	for(i=0;i<n;i++)
   		scanf("%f%f",&p[i],&w[i]);

	for(i=0;i<n;i++){
   		p_w[i] = p[i]/w[i];
    //printf("%f\n",p_w[i]);
	}

	for(i=0;i<n;i++){
	    max = p_w[i];
	    int c=0;
	    for(j=0;j<n;j++){
	        if(max < p_w[j]){
	            max = p_w[j];
	            //printf("max = %f\n",max);
	            c = j;
	        }
	       
	    }
	    pi[i] = c;
	    p_w[c] = 0;
    
  
	}
	printf("The priorities are: \n");
	for(i=0;i<n;i++)
	    printf("Priority of item  %d=%d \n",pi[i]+1,i+1);


	for(i=0;i<n;i++)
	    x[i]=0;

	int u = m;
	for(i=0;i<n;i++){
	    if(u>=w[pi[i]]){
        	x[pi[i]]=1;
        	u=u-w[pi[i]];
    	}
    	else{
        	x[pi[i]] = u/w[pi[i]];
        	u=0;
    	}    
	}


	float sol=0;
	for(i=0;i<n;i++){
    	printf("x[%d] = %f\n",i,x[i]);
    	sol+=p[i]*x[i];
	}
	printf("Solution = %f\n",sol);
}
