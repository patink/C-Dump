#include<stdio.h>
#include<omp.h>

int main(void)
{
  int sum = 0, total_sum = 0, n;
  printf("Total no. of numbers: ");
  scanf("%d", &n);
  
  int a[n], b[n];
  for(int i = 0; i < n; i++)
  {
    printf("\nValue of %dth number of a: ", i+1);
    scanf("%d", &a[i]);
    printf("\nValue of %dth number of b: ", i+1);
    scanf("%d", &b[i]);
  }
  #pragma omp parallel for private(sum) reduction(+:total_sum)
  for(int i = 0; i < n; i++)
  {
    sum = a[i] + b[i];
    printf("\nSum of %dth a and b is: %d", i+1, sum);
    total_sum = total_sum + sum;
  }
  printf("\nThe total sum = %d", total_sum);
}
