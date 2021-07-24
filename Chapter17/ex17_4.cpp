#include "ex17_4.h"


void ex4(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments!";
		exit(EXIT_FAILURE);
	}

	std::ofstream fOut(argv[3], std::ios_base::out);
	std::ifstream fIn1(argv[1], std::ios_base::in);
	std::ifstream fIn2(argv[2], std::ios_base::in);

	if (!fIn1.is_open() ) 
	{
		std::cerr << "Error when opening a file " << argv[1] << " for reading.";
		exit(EXIT_FAILURE);
	}
	else if (!fIn2.is_open())
	{
		std::cerr << "Error when opening a file " << argv[2] << " for reading.";
		exit(EXIT_FAILURE);
	}
	else if (!fOut.is_open())
	{
		std::cerr << "Error when opening a file " << argv[3] << " for writing.";
		exit(EXIT_FAILURE);
	}
	else
	{
		std::string line1;
		std::string line2;
		bool end = false;
		bool good1 = true, good2 = true;

		while (!end)
		{
			if (fIn1.good())
				std::getline(fIn1, line1);
			else
			{
				good1 = false;
				line1 = "";
			}
			if (fIn2.good())
				std::getline(fIn2, line2);
			else
			{
				good2 = false;
				line2 = "";
			}
			if (good1 || good2)
				fOut << line1 + " " + line2 << "\n";
			else end = true;
		}

		fIn1.close();
		fIn2.close();
		fOut.close();
	}
	exit(EXIT_SUCCESS);
}
