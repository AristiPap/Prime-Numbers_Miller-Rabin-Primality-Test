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

/************************* Miller-Rabin algorithm***************************************/

clock_t begin = clock();

for (n=MINNUM+1;n<=MAXNUM;n+=2)
{
        d=n-1;
        r=0;
        //d must be an odd number in order to continue
        while (d%2==0)
        {
        	d=d/2;
        	r++;
       	}
	//the term "condition" is used to check whether a nymber is prime or not according to the miller algorithm
        condition=1;
        i=0;
  while (i<=2 && condition)
  {
        condition=0;
	//for every a that's part of the total [2,7,61]
        if (i==0) a=2;
        if (i==1) a=7;
        if (i==2) a=61;
	//base
        p=a%n;
	//exponent
        k=d;
	//result
        x=1;
	//the exponent must be positive
        while (k>0)
        {
        	if (k%2==1)
                   x=(x*p)%n;
        	p=(p*p)%n;
	//when the exponent is divided by 2 ,the base can be risen to the square
       		 k=k/2;
       	}
	//the following lines are translated in C based on the pseudocode that was given
        if(x==1 || x==n-1)
            condition=1;
         j=1;
	  
	//we use the !condition in order for this loop not to take place if the previous term is true
        while (!condition && j<=r-1)
       	{
        	x=(x*x)%n;
 	        if (x==n-1)
               	   condition=1;
                j++;
        }

	//stepping stone as we increase the value of i and we move on to check the next value for 'a'
        if (condition) i++;
   }
	//this condition is used to check if the upper loop has exceeded the value of 'i' it should check.If true then we have found a prime number
   if (i==3){
      sum++;
   }

}
printf("According to the Miller-Rabin algorithm the sum of prime numbers between the numbers given is: %d\n", sum);
clock_t end = clock();
double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
printf("Time elapsed:%f \n", time_spent);

/******************* endOfMain*************************/
}
/***time elapsed for the Miller-Rabin algorithm:5.166687***/
