#pragma once

#include "Util.h"

#include <algorithm>

namespace Problems
{
	unsigned long long maximumPathSum()
	{
		std::vector<std::string> lines = Util::GetLinesOfFile("Inputs/Problem 18.txt");

		std::vector<std::vector<unsigned long long>> rows(lines.size());

		for (unsigned int i = 0; i < lines.size(); i++)
		{
			auto numbers = Util::Split(lines[i], ' ');
			rows[i].resize(numbers.size());

			for (unsigned int j = 0; j < numbers.size(); j++)
			{
				rows[i][j] = std::atoi(numbers[j].c_str());
			}
		}

		for (unsigned int i = rows.size() - 1; i > 0; i--)
		{
			for (unsigned int j = 0; j < rows[i].size() - 1; j++)
			{
				unsigned long long greater = std::max(rows[i][j], rows[i][j + 1]);

				rows[i - 1][j] += greater;
			}
		}

		return rows[0][0];
	}
}