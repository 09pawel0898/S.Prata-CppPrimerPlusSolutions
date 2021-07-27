#ifndef EX18_1_H
#define EX18_1_H

#include "includes.h"

/* ------- ex 1 -------*/

void ex1(void);

// declaring static functions just for visualize this compilation unit interface in header file

template <typename T>
static double average_list(std::initializer_list<T> args);

#endif