#pragma once

#include "BigInt.h"

namespace BigMath
{
	BigInt Pow(BigInt n, unsigned long long e)
	{
		if (e == 0)
		{
			return BigInt(0u);
		}

		BigInt ret(n);
		for (unsigned int i = 1; i < e; i++)
		{
			ret = ret * n;
		}

		return ret;
	}

	BigInt Factorial(unsigned long long n)
	{
		BigInt result(n);
		for (unsigned int i = n - 1; i > 0; i--)
		{
			result = result * BigInt(i);
		}

		return result;
	}
}