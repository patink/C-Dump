#include<stdio.h>
#include<omp.h>

int main(void)
{
  int nthreads, tid;
  
  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    printf("Hello World from thread = %d\n", tid);
    if(tid == 0) // This block is only executed by master thread
    {
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d\n", nthreads);
    }
  }
}
