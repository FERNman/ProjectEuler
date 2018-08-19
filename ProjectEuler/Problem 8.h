#pragma once

#include "Util.h"

namespace Problems
{
	unsigned long long largestProductInSerie(std::string serie, unsigned int adjacentCount)
	{
		unsigned long long max = 0;
		for (unsigned int i = 0; i < serie.length() - 1 - adjacentCount; i++)
		{
			unsigned long long current = 1;
			for (unsigned int j = 0; j < adjacentCount; j++)
			{
				int n = serie[i + j] - '0';

				current *= n;
			}

			if (current > max)
			{
				max = current;
			}
		}

		return max;
	}
}
