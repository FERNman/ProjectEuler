#pragma once

#include <string>

#include "BigInt.h"
#include "BigMath.h"

namespace Problems
{
	unsigned long long factorialDigitSum()
	{
		auto number = BigMath::Factorial(100);
		
		unsigned long long sum = 0;

		for (auto digit : number.GetDigits())
		{
			sum += digit;
		}

		return sum;
	}
}