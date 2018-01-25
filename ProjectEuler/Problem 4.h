#pragma once

#include <string>

namespace Problems
{
	unsigned long long largestPalindromeProduct()
	{
		unsigned long long max = 0;

		for (unsigned int i = 999; i >= 100; i--)
		{
			for (unsigned int j = 999; j >= 100; j--)
			{
				unsigned long long sum = i * j;

				if (sum > max)
				{
					std::string actual = std::to_string(sum);
					std::string reverse(actual.rbegin(), actual.rend());

					if (actual == reverse)
					{
						max = sum;
					}
				}
			}
		}

		return max;
	}
}
