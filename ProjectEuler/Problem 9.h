#pragma once

#include <algorithm>

namespace Problems
{
	unsigned long long specialPythagoreanTriplet()
	{
		unsigned int sum = 1000;

		for (unsigned int a = sum; a > 0; a--)
		{
			for (unsigned int b = sum; b > a; b--)
			{
				float c = sqrt(a * a + b * b);

				if (floor(c) == c)
				{
					if (a + b + c == sum)
					{
						return a * b * c;
					}
				}
			}
		}

		return 0;
	}
}