#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    return (x>>n)&1;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    unsigned T = *x;
    unsigned T1,T2;
    if(v==0)
    {
    	if(n==0)
    	{
    		*x=*x>>1<<1;
    	}
    	else //n!=0;
    	{
    		T1 = (*x>>(n+1)<<(n+1));
    		T2 = T<<(32-n)>>(32-n);
    		*x = T1 | T2;
    	}
    }
    else  //v==1
    {
    	if(n==0)
    	{
    		*x = *x | 1;
    	}
    	else //n!=0;
    	{
    		*x=(*x>>n) | v;
    		*x = (*x<<n) | (T<<(32-n)>>(32-n));
    	}
    }
    
  //  return *x;
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) 
{
    // YOUR CODE HERE
    unsigned T = ~(*x);
    unsigned T1,T2;
    T=T>>n<<31>>31-n;
    if(T != 0)
    {
    	*x= *x | T;
    }
    else //T=0;
    {
    	if(n==0)
    	{
    		*x = *x>>1<<1;
    	}
    	else //n!=0
    	{
    		T1 = (*x>>(n+1)<<(n+1));
    		T2 = (*x<<(32-n)>>(32-n));
    		*x = T1 | T2;
    	}
    }
   // return *x;
    

}

