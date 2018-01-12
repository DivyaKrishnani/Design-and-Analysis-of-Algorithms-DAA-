#include <stdio.h>

struct Job {
	char id[5];
	int deadline;
	int profit;
};

int min(int x, int y) {
    if(x < y)
         return x;
    return y;
}


void jobSequence(struct Job jobs[], int n) {

	int i, j, k, maxprofit;
    int timeslot[100];
	int res[100];

	int dmax = 0;
	for(i = 0; i < n; i++) {
		if(jobs[i].deadline > dmax) {
			dmax = jobs[i].deadline;
		}
	}

	for(i = 0; i < n; i++) {
		timeslot[i] = -1;
	}

	
	for (int i=0; i<n; i++)
    {
       
       for (int j=min(dmax, jobs[i].deadline)-1; j>=0; j--)
       {

          if (timeslot[j]==-1)
          {
             res[j]=i; 
             timeslot[j] = 1; 
             break;
          }
       }
    }

	printf("\nRequired Jobs: ");
	for(i = 0; i <n; i++) {
		if(timeslot[i]==1){
			printf("%s", jobs[res[i]].id);

			if(i < n-1) {
				printf(" --> ");
			}
		}
	}
	
	maxprofit = 0;
	for(i = 0; i < n; i++) {
		if(timeslot[i]==1){
			maxprofit += jobs[res[i]].profit;
		}
	}
	printf("\nMax Profit: %d\n", maxprofit);
}


int main(void) {
     int i, j;
     int n;
     struct Job jobs[10];
     printf("How many Jobs? ");
     scanf("%d",&n);
     printf("%s %s %s\n", "Job", "Deadline", "Profit");
     for(i=0;i<n;i++)
           scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
     struct Job temp;
     
     for(i = 0; i < n; i++) {
		for(j = 0; j < n - i; j++) {
			if(jobs[j+1].profit > jobs[j].profit) {
				temp = jobs[j+1];
				jobs[j+1] = jobs[j];
				jobs[j] = temp;
			}
		}
	}

	printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
        for(i = 0; i < n; i++) {
	       printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
	}

	jobSequence(jobs, n);

	return 0;
}

/*
eg.
How many Jobs? 4
Job Deadline Profit
a 4 20 
b 1 10
c 1 10
d 1 30

eg. 2
j1 4 200
j2 6 50
j3 3 100
j4 2 70
j5 3 80
j6 1 85
j7 4 72



*/
