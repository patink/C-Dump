#include<stdio.h>
#include<omp.h>

int main(void)
{
  int c;
  int a[] = {1,2,3,4,5,6,7,8};
  #pragma omp parallel for lastprivate(c)
  for(int i = 0; i < 8; i++)
  {
    c = a[i]*a[i]*a[i];
    printf("\nCube of number in %dth index: %d", i, c);
  }
  printf("\nCube of the last index(highest possible index): %d", c);
}
