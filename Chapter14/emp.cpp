#include <string>
#include <iostream>

#include "emp.h"

using std::cout;
using std::cin;


abstr_emp::abstr_emp()
{}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	:	fname(fn),
		lname(ln),
		job(j)
{}

abstr_emp::~abstr_emp()
{}

void abstr_emp::ShowAll() const
{
	cout << "First name : " << fname << "\nLast name : " << lname << "\nJob : " << job << "\n";
}

void abstr_emp::SetAll()
{
	cout << "Enter new values. \n";
	cout << "First name : ";
	cin >> fname;
	cout << "Last name : ";
	cin >> lname;
	cout << "Job : ";
	cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname;
	return os;
}


employee::employee()
	:	abstr_emp()
{}

employee::employee(const std::string& fn, const std::string& ln,
	const std::string& j)
	: abstr_emp(fn,ln,j)
{}


void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager()
	:	abstr_emp(),
		inchargeof(0)
{}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
	:	abstr_emp(fn,ln,j),
		inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	:	abstr_emp(e),
		inchargeof(ico)
{}

manager::manager(const manager& m)
	:	abstr_emp(m)
{
	inchargeof = m.InChargeOf();
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "In charge of : " << inchargeof << "\n";
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "In charge of : ";
	cin >> inchargeof;
}

fink::fink()
	:	abstr_emp(),
		reportsto("")
{}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	:	abstr_emp(fn, ln, j),
		reportsto(rpo)
{}

fink::fink(const abstr_emp& e, const std::string& rpo)
	:	abstr_emp(e),
		reportsto(rpo)
{}

fink::fink(const fink& m)
	:	abstr_emp(m)
{
	reportsto = m.ReportsTo();
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Report : " << reportsto << "\n";
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Report : ";
	cin >> reportsto;
}

highfink::highfink() : abstr_emp(), manager(), fink()
{}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
	:	abstr_emp(fn, ln, j), 
		manager(fn, ln, j, ico),
		fink(fn, ln, j, rpo)
{}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	:	abstr_emp(e), 
		manager(e, ico), 
		fink(e, rpo)
{}

highfink::highfink(const fink& f, int ico)
	:	abstr_emp(f), 
		manager(f, ico), 
		fink()
{}

highfink::highfink(const manager& m, const std::string& rpo)
	:	abstr_emp(m), 
		manager(), 
		fink(m, rpo)
{}

highfink::highfink(const highfink& h) 
	:	abstr_emp(h), 
		manager(h), 
		fink(h)
{}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "In charge of : " << InChargeOf() << "\n";
	cout << "Reports : " << ReportsTo() << "\n";
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "In charge of : ";
	cin >> InChargeOf();
	cout << "Report : ";
	cin >> ReportsTo();

}










