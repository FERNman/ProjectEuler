#pragma once

namespace Problems
{
	unsigned int longestCollatzSequence()
	{
		unsigned long long maxCount = 0;
		unsigned int maxNumber = 0;

		for (unsigned int i = 1; i < 1000000; i++)
		{
			unsigned long long current = i;
			unsigned long long currentCount = 0;

			while (current != 1)
			{
				if (current % 2 == 0)
				{
					current = current / 2;
				}
				else
				{
					current = current * 3 + 1;
				}

				currentCount++;
			}

			if (currentCount > maxCount)
			{
				maxCount = currentCount;
				maxNumber = i;
			}
		}

		return maxNumber;
	}
}