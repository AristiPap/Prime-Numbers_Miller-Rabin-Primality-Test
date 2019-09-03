#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MINNUM 3990000000
#define MAXNUM 4010000000

int main()
{
unsigned int x1,z,sum1;
int a, r, i, condition, j, sum=0;
unsigned int n, d, k, y;
unsigned long long x,p;
/****************************************Deterministic algorithm**************/
clock_t start = clock();

sum1=0;

// ^ get rid of all the even numbers by adding two from the first odd number until we reach the maximum number given
for(x1=(MINNUM+1);x1<=(MAXNUM);x1+=2)
{
//we only check the odd numbers that aren't divided by three
        if((x1)%3!=0)
        {
           z=1;
          // the first divident(n)
           y=5;
           //we are looking for a divident that is equal or smaller than the square root of the number given
           while((z) &&  y*y<=x1){
             if(((x1)%y==0) || ((x1)%(y+2)==0)){
                 //when z=0 then x1  is not prime
                  z=0;
             }
             // the rest of the dividents that occur if we add 6 to the number n and n+2
             y+=6;
           }
           //when z=1  then x1 is a prime
           if (z==1){
              sum1++;
           }
        }
}
printf("According to the deterministic algorithm the sum of prime numbers between the numbers given is: %d\n", sum1);
clock_t finish = clock();
double time_elapsed = (double)(finish-start) / CLOCKS_PER_SEC;
printf("Time elapsed:%f \n", time_elapsed);
}

/*****time elapsed for the deterministic algorithm:52.488000********/
