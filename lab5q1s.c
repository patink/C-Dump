#include<stdio.h>
#include<omp.h>
#define _GNU_SOURCE
#include <sched.h>
int sched_getcpu(void);
int main(void)
{
  int x[10],y[10];
  int i, sum[10];  
  for(i = 0; i < 10; i++)
  {
    printf("\nENTER THE VALUES OF %d th x AND y:",i+1);
    scanf("%d",&x[i]);
    scanf("%d",&y[i]);
  }
  
  #pragma omp parallel for schedule(static, 1)
  for(i=0; i<10; i++)
  {
    sum[i] = x[i] + y[i];
    printf("For i value:%d\tCPU:%d\tThread:%d\tValue:%d\n",i+1,sched_getcpu(),omp_get_thread_num(),sum[i]);
  }
}
