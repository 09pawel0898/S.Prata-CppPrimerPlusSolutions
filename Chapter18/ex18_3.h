#ifndef EX18_3_H
#define EX18_3_H

#include "includes.h"

/* ------- ex 3 -------*/

void ex3(void);


template <typename T>
long double sum_values(T val)
{ 
	return val; 
}

template <typename T, typename... Args>
long double sum_values(T val, Args... args)
{
	return val + sum_values(args...);
}


#endif