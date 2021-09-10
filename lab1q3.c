#include<stdio.h>
#include<omp.h>

int main(void)
{
  int tid;
  
  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    printf("Name - NISITH KUMAR PATI from thread = %d\n", tid);
    if(tid == 5) // This block is only executed by the 4th thread
    {
      printf("Registration number - 19BCE1094 from thread = %d\n", tid);
    }
  }
}
