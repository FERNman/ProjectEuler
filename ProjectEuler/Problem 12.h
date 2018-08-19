#pragma once

namespace Problems
{
	unsigned long long highlyDivisibleTriangularNumber()
	{
		unsigned int minDivisors = 500;
		unsigned long long current = 1;

		while (true)
		{
			unsigned long long triangleNumber = 0;
			for (unsigned int i = 1; i <= current; i++)
			{
				triangleNumber += i;
			}

			unsigned int currentDivisors = 0;
			for (unsigned int i = 1; i <= sqrt(triangleNumber); i++)
			{
				if (triangleNumber % i == 0)
				{
					currentDivisors += 2;
				}
			}

			if (currentDivisors > minDivisors)
			{
				return triangleNumber;
			}

			current++;
		}
	}
}