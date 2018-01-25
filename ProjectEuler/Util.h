#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

namespace Util
{
	std::vector<std::string> GetLinesOfFile(std::string filename)
	{
		std::vector<std::string> lines;

		std::ifstream input(filename);
		if (!input.is_open())
		{
			std::cout << "Failed to open input " << filename << std::endl;
			return lines;
		}

		std::string line;
		while (std::getline(input, line))
		{
			lines.push_back(line);
		}

		return lines;
	}

	std::vector<std::string> Split(const std::string& s, char delimiter)
	{
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);

		while (std::getline(tokenStream, token, delimiter))
		{
			tokens.push_back(token);
		}

		return tokens;
	}

	unsigned long long Factorial(unsigned long long n)
	{
		return (n == 1 || n == 0) ? 1 : Factorial(n - 1) * n;
	}

	bool IsPrime(unsigned long long number)
	{
		unsigned long long root = sqrt(number);

		for (unsigned long long i = 2; i < root; i++)
		{
			if (number % i == 0)
			{
				return false;
			}
		}

		return true;
	}
}