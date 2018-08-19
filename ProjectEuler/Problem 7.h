#pragma once

#include "Util.h"

namespace Problems
{
	unsigned long long nstPrime()
	{
		unsigned int n = 10001;
		unsigned long long i = 1;
		unsigned int count = 0;

		while (count < n)
		{
			i++;

			if (Util::IsPrime(i))
			{
				count++;
			}
		}

		return i;
	}
}
