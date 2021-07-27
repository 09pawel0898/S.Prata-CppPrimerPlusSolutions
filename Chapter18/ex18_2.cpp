#include "ex18_2.h"

void ex2(void)
{
    
}

Cpmv::Cpmv()
{
    pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z)
    :   Cpmv()
{
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv& cp)
    :   Cpmv()
{
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv&& mv) noexcept
{
    delete pi;
    this->pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    delete pi;
}

void Cpmv::Display(void) const
{
    std::cout << "qcode : " << pi->qcode << "\nzcode : " << pi->zcode<<"\n";
}