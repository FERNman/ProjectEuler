#pragma once

#include "Util.h"

namespace Problems
{
	unsigned long long summationOfPrimes()
	{
		unsigned long long max = 2000000;
		unsigned long long sum = 0;

		for (unsigned int i = 2; i < max; i++)
		{
			if (Util::IsPrime(i))
			{
				sum += i;
			}
		}

		return sum;
	}
}