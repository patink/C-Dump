#include<stdio.h>
#include<omp.h>
#include<unistd.h>

int main(void)
{
  int n, available, produced = 0, consumed = 0;
  printf("MAX ITEMS TO BE PRODUCED: ");
  scanf("%d", &n);
  #pragma omp parallel shared(produced, consumed)
  {
    #pragma omp master
    {
      for(int i = 0; i< n; i++)
      {
        printf("\nPRODUCER IS PRODUCING AN ITEM ");
        sleep(2); // 2s is taken by the producer to produce the item
        printf("\nPRODUCTION NUMBER INCREMENTED");
        #pragma omp critical
        {
          produced = produced + 1;
        }
      }
    }
    if(omp_get_thread_num() != 0) //All the threads(excluding master)
    {
      while(consumed != n) // If consumed item is equal to max produced then no more items consumed
      {
        int isConsumed = 0; // if consumed sleeps for 5 seconds
        #pragma omp critical
        {
          if(produced > 0)
          {
            produced = produced - 1;
            consumed = consumed + 1;
            printf("\nCONSUMER WITH TID %d HAS CONSUMED THE ITEM: %d",omp_get_thread_num(), consumed);
            isConsumed = 1;
          }
        }
        if(isConsumed == 1)
        {
          sleep(5); // consumer takes 5 seconds to consume an item
        }
      } 
    }
  }
}
