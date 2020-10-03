#pragma GCC optimize("O3")
#include <stdio.h>
#include <time.h>

#define SIZE 1000

float a[SIZE][SIZE];
float b[SIZE][SIZE];
float c[SIZE][SIZE];

void init(void)
{
   int i, j, k;
   for(i=0; i<SIZE; ++i)
   {
      for(j=0; j<SIZE; ++j)
      {
         a[i][j] = (float)i + j;
         b[i][j] = (float)i - j;
         c[i][j] = 0.0f;
      }
   }
}

void mult(void)
{
   int i, j, k;

   for(i=0; i<SIZE; ++i)
   {
      for(j=0; j<SIZE; ++j)
      {  
         for(k=0; k<SIZE; ++k)
         {  
            c[i][j] += a[i][k] * b[k][j];
         }  
      }
   }
}

int main(void)
{
   clock_t s, e;
   init();
   s=clock();
   mult();
   e=clock();
   printf("mult took %10d clocks\n", (int)(e-s));
   return 0;

}

