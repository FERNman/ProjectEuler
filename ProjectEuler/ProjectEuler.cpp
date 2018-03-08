// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

bool isPrime(unsigned long long number)
{
	unsigned long long root = sqrt(number);

	for (unsigned long long i = 0; i < root; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

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

unsigned long long nstPrime(unsigned int n)
{
	unsigned long long i = 1;
	unsigned int count = 0;
	
	while (count < n)
	{
		i++;

		bool prime = true;
		for (unsigned long long j = i - 1; j > 1; j--)
		{
			if (i % j == 0)
			{
				prime = false;
			}
		}

		if (prime)
		{
			count++;
		}
	}

	return i;
}

enum Weekday
{
	Monday = 0,
	Tuesday = 1,
	Wednesday = 2,
	Thursday = 3,
	Friday = 4,
	Saturday = 5,
	Sunday = 6
};

enum Month
{

};

unsigned long long countingSundays()
{
	unsigned long long count = 0;
	Weekday currentWeekday = Monday;

	for (unsigned int year = 1901; year < 2001; year++)
	{
		bool leapYear = (year % 4 == 0);
		for (unsigned int day = 1; day <= (leapYear ? 366 : 365); day++)
		{
			if (currentWeekday < 6)
			{
				currentWeekday = static_cast<Weekday>(static_cast<int>(currentWeekday) + 1);
			}
			else if (currentWeekday >= 6)
			{
				currentWeekday = Monday;
			}
		}
	}
}

int main()
{
	std::cout << nstPrime(10001) << std::endl;

	system("pause");
	return 0;
}