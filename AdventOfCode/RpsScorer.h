#pragma once

#include <string>
#include <unordered_map>

class RpsScorer
{
public:
	RpsScorer();
	int TotalScore(const std::string &filePath);

private:
	int SingleScore(const char *elf, const char *human);
	std::unordered_map<char, int> map;

};
