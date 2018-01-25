#pragma once

namespace Problems
{
	unsigned long long smallestMultiple()
	{
		unsigned int max = 20;
		unsigned long long current = max;

		while (true)
		{
			bool divisible = true;
			for (unsigned int i = 1; i <= max; i++)
			{
				if (current % i != 0)
				{
					divisible = false;
					break;
				}
			}

			if (divisible)
			{
				return current;
			}
			else
			{
				current++;
			}
		}
	}
}
