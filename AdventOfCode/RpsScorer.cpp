#include <string>
#include "RpsScorer.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <vector>

/// <summary>
/// Rock: A, X
/// Paper: B, Y
/// Scissors: C, Z
/// </summary>
RpsScorer::RpsScorer()
{
	this->map;

	map['A'] = 1;
	map['X'] = 1;
	map['B'] = 2;
	map['Y'] = 2;
	map['C'] = 3;
	map['Z'] = 3;

}

int RpsScorer::TotalScore(const std::string &filePath)
{
	std::ifstream myFile(filePath);
	std::string myText;
	int fin = 0;

	while (getline(myFile, myText))
	{
		// maybe? Start again here.
		auto choices = split(myText, ' ');
		fin += SingleScore(&choices.at(0), &choices.at(1));
	}

	return fin;
}

int RpsScorer::SingleScore(const char *elf, const char *human)
{
	int ret = map[*human];
	char val = *human;
	if (map[(*elf)] == map[*human]) return ret + 3;

	switch (*elf)
	{
	case 'A':
		if (val == 'Y')
		{
			ret += 6;
		}
		break;
	case 'B':
		if (val == 'Z')
		{
			ret += 6;
		}
		break;
	case 'C':
		if (val == 'X')
		{
			ret += 6;
		}
		break;
	}

	return ret;
}

template <typename Out>
void split(const std::string& s, char delim, Out result) {
	std::istringstream iss(s);
	std::string item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}

std::vector<char> split(const std::string& s, char delim)
{
	std::vector<char> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}