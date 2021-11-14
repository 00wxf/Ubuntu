#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t T1,T2,T3,T4,T5;

    	T1 = *reg & 1;
    	T2 = *reg >> 2 & 1;
    	T3 = *reg >> 3 & 1;
    	T4 = *reg >> 5 & 1;
    	T5 = (T4^(T3^(T1^T2)));
    	
    	*reg = *reg >> 1;
    	
    	if(T5 == 1)
    	{
    		T5 = T5 << 15;
    		*reg = *reg | T5;
    	}
    	
    
}

