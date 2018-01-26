// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <sstream>

bool isPrime(unsigned long long number)
{
	if (number < 2)
	{
		return false;
	}

	unsigned long long root = sqrt(number);

	for (unsigned long long i = 2; i <= root; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

std::vector<std::string> splitString(const std::string &s, char delimiter)
{
	std::vector<std::string> pieces;
	std::string piece;

	std::istringstream piecesStream(s);

	while (std::getline(piecesStream, piece, delimiter))
	{
		pieces.push_back(piece);
	}

	return pieces;
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

unsigned long long largestProductInSerie(std::string serie, unsigned int adjacentCount)
{
	unsigned long long max = 0;
	for (unsigned int i = 0; i < serie.length() - 1 - adjacentCount; i++)
	{
		unsigned long long current = 1;
		for (unsigned int j = 0; j < adjacentCount; j++)
		{
			int n = serie[i + j] - '0';

			current *= n;
		}

		if (current > max)
		{
			max = current;
		}
	}

	return max;
}

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

unsigned long long summationOfPrimes()
{
	unsigned long long max = 2000000;
	unsigned long long sum = 0;

	for (unsigned int i = 2; i < max; i++)
	{
		if (isPrime(i))
		{
			sum += i;
		}
	}

	return sum;
}

unsigned long long largestProductInAGrid()
{
	std::string grid = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

	std::vector<std::string> splitGrid = splitString(grid, ' ');

	unsigned int current = 0;
	for (unsigned int i = 0; i < 20; i++)
	{
		for (unsigned int j = 0; j < 20; j++)
		{

		}
	}
}

int main()
{
	std::cout << summationOfPrimes() << std::endl;

	system("pause");
	return 0;
}