#pragma once

namespace Problems
{
	unsigned long long sumSquareDifference()
	{
		unsigned int max = 100;
		unsigned long long sumOfSquares = 0;
		unsigned long long sum = 0;

		for (unsigned int i = 1; i <= max; i++)
		{
			sumOfSquares += i * i;
			sum += i;
		}

		unsigned long long square = sum * sum;

		return square - sumOfSquares;
	}
}
