#pragma once

#include "Util.h"

namespace Problems
{
	struct Position
	{
		Position()
		{
			row = 0;
			col = 0;
			sum = 0;
		}

		unsigned int row;
		unsigned int col;
		unsigned int sum;

		bool operator>(const Position &other)
		{
			return this->sum > other.sum;
		}

		bool operator<(const Position &other)
		{
			return this->sum < other.sum;
		}
	};

	unsigned long long maximumPathSum()
	{
		std::vector<std::string> lines = Util::GetLinesOfFile("Inputs/Problem 18.txt");

		std::vector<std::vector<unsigned int>> rows(lines.size());

		for (unsigned int i = 0; i < lines.size(); i++)
		{
			auto numbers = Util::Split(lines[i], ' ');
			rows[i].resize(numbers.size());

			for (unsigned int j = 0; j < numbers.size(); j++)
			{
				rows[i][j] = std::atoi(numbers[j].c_str());
			}
		}

		Position p;
		p.sum = rows[0][0];

		for (unsigned int i = 1; i < rows.size(); i++)
		{
			if (rows[i][p.col] > rows[i][p.col + 1])
			{
				p.sum += rows[i][p.col];
			}
			else
			{
				p.sum += rows[i][p.col + 1];
				p.col++;
			}

			p.row++;
		}

		return p.sum;
	}
}