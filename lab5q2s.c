#include<stdio.h>
#include<omp.h>
int main(void)
{
  int i = 9;  
  #pragma omp parallel for schedule(static,2) firstprivate(i)
    for(int j=0;j<9;j++)
    {
      i = i+j;
      printf("i = %d\n",i);
    }
}
