#pragma once

#include "BigInt.h"

namespace BigMath
{
	BigInt Pow(BigInt n, unsigned long long e)
	{
		if (e == 0)
		{
			return BigInt(0);
		}

		BigInt ret(n);
		for (unsigned int i = 1; i < e; i++)
		{
			ret = ret * n;
		}

		return ret;
	}
}