#ifndef EX17_7_H
#define EX17_7_H

#include "includes.h"


/* ------- ex 7 -------*/

void ex7(void);

class Store
{
	std::ofstream& stream;

public:

	explicit Store(std::ofstream& ofstream)
		:	stream(ofstream)
	{}

	void operator()(const std::string& str)
	{
		std::size_t len = str.length();
		stream.write((char*)&len, sizeof(std::size_t));
		stream.write(str.data(), len);
	}
};

// declaring static functions just for visualize this compilation unit interface in header file

static void showStr(const std::string& str);
static bool getStrs(std::ifstream& is, std::vector<std::string>& vec);

#endif