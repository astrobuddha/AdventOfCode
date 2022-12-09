#include "CalorieCount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int CalorieCount::GetBestElf(const std::string filePath) 
{
	std::ifstream myFile(filePath);
	std::string myText;
	std::vector<int> totals;
	int fin = 0;

	int curr = 0;

	while (getline(myFile, myText))
	{
		if (myText.empty())
		{
			totals.push_back(curr);
			curr = 0;
		}
		else
		{
			curr += std::stoi(myText);
		}
	}

	myFile.close();

	sort(totals.begin(), totals.end(), std::greater<int>());

	for (int i = 0; i < 3; ++i)
	{
		fin += totals.at(i);
	}

	return fin;
}
