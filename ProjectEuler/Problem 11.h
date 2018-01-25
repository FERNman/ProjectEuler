#pragma once

#include "Util.h"

namespace Problems
{
	unsigned long long largestProductInAGrid()
	{
		std::vector<std::string> lines = Util::GetLinesOfFile("Inputs/Problem 11.txt");

		std::vector<std::vector<int>> grid(lines.size());

		for (unsigned int i = 0; i < lines.size(); i++)
		{
			auto numbers = Util::Split(lines[i], ' ');

			grid[i].resize(numbers.size());

			for (unsigned int j = 0; j < numbers.size(); j++)
			{
				grid[i][j] = std::atoi(numbers[j].c_str());
			}
		}

		unsigned long long max = 0;

		for (unsigned int y = 0; y < 20; y++)
		{
			for (unsigned int x = 0; x < 20; x++)
			{
				// Product to the right
				if (x + 3 < 20)
				{
					unsigned long long current = grid[y][x] * grid[y][x + 1] * grid[y][x + 2] * grid[y][x + 3];

					if (current > max)
					{
						max = current;
					}
				}

				// Product to the bottom
				if (y + 3 < 20)
				{
					unsigned long long current = grid[y][x] * grid[y + 1][x] * grid[y + 2][x] * grid[y + 3][x];

					if (current > max)
					{
						max = current;
					}
				}

				// Product right bottom diagonal
				if (x + 3 < 20 && y + 3 < 20)
				{
					unsigned long long current = grid[y][x] * grid[y + 1][x + 1] * grid[y + 2][x + 2] * grid[y + 3][x + 3];

					if (current > max)
					{
						max = current;
					}
				}

				// Product left bottom diagonal
				if (static_cast<int>(x) - 3 >= 0 && y + 3 < 20)
				{
					unsigned long long current = grid[y][x] * grid[y + 1][x - 1] * grid[y + 2][x - 2] * grid[y + 3][x - 3];

					if (current > max)
					{
						max = current;
					}
				}
			}
		}

		return max;
	}
}
