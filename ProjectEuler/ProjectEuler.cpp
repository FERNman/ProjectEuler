// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

unsigned int sumBelow(unsigned int max)
{
	unsigned int sum = 0;
	for (unsigned int i = 1; i < max; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}

unsigned int fibonacciEvenSum(unsigned int max)
{
	unsigned int sum = 0;
	unsigned int current = 1;
	unsigned int next = 1;

	while (next < max)
	{
		unsigned int temp = next;
		next = current + next;
		current = temp;

		if (next % 2 == 0)
		{
			sum += next;
		}
	}

	return sum;
}

unsigned long long largestPrimeFactor(unsigned long long number)
{
	unsigned long long max = 0;

	while (number > 1)
	{
		unsigned long long i = 2;
		while(i <= number && number % i != 0)
		{
			i++;
		}

		number /= i;

		if (i > max)
		{
			max = i;
		}
	}

	return max;
}

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

unsigned long long smallestMultiple(unsigned int max)
{
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

unsigned long long sumSquareDifference(unsigned int max)
{
	unsigned long long sumOfSquares = 0;
	unsigned long long sum = 0;

	for (unsigned int i = 1; i <= max; i++)
	{
		sumOfSquares += i * i;
		sum += i;
	}

	unsigned long long square = sum * sum;

	return square - sumOfSquares;
}

int main()
{
	std::cout << sumSquareDifference(100) << std::endl;

	system("pause");
	return 0;
}