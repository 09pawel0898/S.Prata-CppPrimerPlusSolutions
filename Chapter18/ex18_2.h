#ifndef EX18_2_H
#define EX18_2_H

#include "includes.h"


/* ------- ex 2 -------*/


class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi = nullptr;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv) noexcept;
	~Cpmv();

	Cpmv& operator=(const Cpmv& cp) 
	{ 
		if (this == &cp)
			return *this;
		delete pi;
		this->pi = new Info; 
		pi->qcode = cp.pi->qcode; 
		pi->zcode = cp.pi->zcode;
		return *this; 
	};
	Cpmv& operator=(Cpmv&& cp) noexcept 
	{ 
		if (this == &cp)
			return *this;
		delete pi;
		this->pi = cp.pi; 
		cp.pi = nullptr; 
		return *this; 
	};
	Cpmv operator+(const Cpmv& rhs) const {	return { this->pi->qcode + rhs.pi->qcode, this->pi->zcode + rhs.pi->zcode };	}

	void Display(void) const;
};

void ex2(void);

#endif