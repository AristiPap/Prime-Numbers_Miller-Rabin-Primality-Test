# Prime-Numbers
The following programs ,are two different implementations that calculate how many prime numbers exist between two random numbers that are defined inside the code.One of the implementations is based on the Miller-Rabin algorithm(https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test) and the other (deterministic) uses specific tricks to minimize the process time. 

For example:

~Get rid of all the even numbers by adding two from the first odd number until we reach the maximum number given,

~search for all the odd dividents tha aren't divided by 3,

~the rest of the dividents occur if we add 6 to the number n and n+2

Note that each implementation can take input for numbers upto 4090000000  
(if the defined numbers that we use to calculate all the prime numbers in between are: minimum-3990000000
maximum- 4010000000 then the process time for each implementation is:
deterministic algorithm:52.488000sec||
Miller-Rabin algorithm:5.166687sec
