#include<stdio.h>
#include<omp.h>

int main(void)
{
  int n;
  printf("TOTAL NUMBER OF ENTRIES: ");
  scanf("%d", &n);
  
  float x[n], y[n], add[n], sub[n], mul[n], div[n];
  
  for(int i = 0; i < n; i++)
  {
    printf("\n---Enter the value of %dth a: ---", i+1);
    scanf("%f", &x[i]);
    printf("\n---Enter the value of %dth b: ---", i+1);
    scanf("%f", &y[i]);
  }
  
  #pragma omp parallel sections
  {
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        add[i] = x[i] + y[i];
      }
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        sub[i] = x[i] - y[i];
      }
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        mul[i] = x[i] * y[i];
      }
    #pragma omp section
      for(int i = 0; i < n; i++)
      {
        div[i] = x[i] / y[i];
      }
  }
  for(int i = 0; i < n; i++)
  {
    printf("\nThe addition of %.2f and %.2f is : %.2f", x[i], y[i], add[i]);
    printf("\nThe subraction of %.2f and %.2f is : %.2f", x[i], y[i], sub[i]);
    printf("\nThe multiplication of %.2f and %.2f is : %.2f", x[i], y[i], mul[i]);
    printf("\nThe division of %.2f and %.2f is : %f\n", x[i], y[i], div[i]);
  }
}
