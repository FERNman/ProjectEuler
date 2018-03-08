#pragma once

namespace Problems
{
	unsigned long long largestPrimeFactor()
	{
		unsigned long long number = 600851475143;
		unsigned long long max = 0;

		while (number > 1)
		{
			unsigned long long i = 2;
			while (i <= number && number % i != 0)
			{
				i++;
			}

			number /= i;

			if (i > max)
			{
				max = i;
			}
		}

		return max;
	}
}
