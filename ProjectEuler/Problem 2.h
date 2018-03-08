#pragma once

namespace Problems
{
	unsigned int evenFibonacciNumbers()
	{
		unsigned int max = 4000000;
		unsigned int sum = 0;
		unsigned int current = 1;
		unsigned int next = 1;

		while (next < max)
		{
			unsigned int temp = next;
			next = current + next;
			current = temp;

			if (next % 2 == 0)
			{
				sum += next;
			}
		}

		return sum;
	}
}
