#include<stdio.h>
#include<omp.h>

int main(void)
{
  int a = 0, b = 0, c = 0;
  #pragma omp parallel shared(a)
  {
    #pragma omp critical
    a = a+1;
    #pragma omp master
    b = b+1;
    #pragma omp single
    c = c+1;
  }
  printf("Using the critical value of a: %d",a);
  printf("\nUsing the master value of b: %d",b);
  printf("\nUsing the single value of c: %d",c);
}
