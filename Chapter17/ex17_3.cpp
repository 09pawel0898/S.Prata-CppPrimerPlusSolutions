#include "ex17_3.h"


void ex3(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Incorrect number of arguments!";
		exit(EXIT_FAILURE);
	}

	std::ofstream fOut(argv[2], std::ios_base::out);
	std::ifstream fIn(argv[1],std::ios_base::in);

	if (!fIn.is_open())
	{
		std::cerr << "Error when opening a file " << argv[1] << " for reading.";
		exit(EXIT_FAILURE);
	}
	else if (!fOut.is_open())
	{
		std::cerr << "Error when opening a file " << argv[2] << " for writing.";
		exit(EXIT_FAILURE);
	}
	else
	{
		std::string line;
		while (fIn.good())
		{
			std::getline(fIn, line);
			fOut << line << "\n";
		}

		fIn.close();
		fOut.close();
	}
	exit(EXIT_SUCCESS);
}