#include "CalorieCount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int CalorieCount::GetBestElf(std::string filePath) 
{
	std::ifstream myFile(filePath);
	std::string myText;
	int fin = 0;

	int curr = 0;

	while (getline(myFile, myText))
	{
		if (myText.empty())
		{
			fin = curr > fin ? curr : fin;
			curr = 0;
		}
		else
		{
			curr += std::stoi(myText);
		}
	}

	myFile.close();

	return fin;
}
