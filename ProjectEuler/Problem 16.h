#pragma once

#include "BigInt.h"
#include "BigMath.h"

namespace Problems
{
	std::string powerDigitSum()
	{
		BigInt myInt(2u);

		BigInt product = BigMath::Pow(myInt, 1000);

		auto digits = product.GetDigits();

		unsigned long long sum = 0;

		for (unsigned int i = 0; i < digits.size(); i++)
		{
			sum += digits[i];
		}

		return std::to_string(sum);
	}
}