#pragma once

#include "Util.h"
#include "BigInt.h"

namespace Problems
{
	std::string largeSum()
	{
		std::vector<std::string> lines = Util::GetLinesOfFile("Inputs/Problem 13.txt");

		std::vector<BigInt> numbers;

		for (auto line : lines)
		{
			numbers.push_back(BigInt(line));
		}

		BigInt sum;
		for (auto number : numbers)
		{
			sum = sum + number;
		}

		return sum.to_string().substr(0, 10);
	}
}