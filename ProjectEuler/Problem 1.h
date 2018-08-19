#pragma once

namespace Problems
{
	unsigned int multiplesOfThreeAndFive()
	{
		unsigned int max = 1000;
		unsigned int sum = 0;

		for (unsigned int i = 1; i < max; i++)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				sum += i;
			}
		}

		return sum;
	}
}
