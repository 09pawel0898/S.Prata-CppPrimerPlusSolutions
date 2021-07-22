#include "includes.h"

#ifndef EX16_6_H
#define EX16_6_H


/* ------- ex 6 -------*/

void ex6(void);

class Customer
{
private:
    long arrive;     // czas do³¹czenia klienta do kolejki
    int processtime; // czas obs³ugi klienta
public:
    Customer() { arrive = processtime = 0; }
    void set(long when)
    {
        processtime = std::rand() % 3 + 1;
        arrive = when;
    }
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};


// declaring static functions just for visualize this compilation unit interface in header file
static bool newcustomer(double x);

#endif