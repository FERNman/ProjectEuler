// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#include "BigInt.h"
#include "BigMath.h"
#include "NumbersInWords.h"

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

unsigned long long factorial(unsigned long long n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

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

unsigned long long largestProductInAGrid()
{
	std::string sgrid = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

	auto splitGrid = split(sgrid, ' ');

	std::vector<std::vector<int>> grid(20);

	for (unsigned int y = 0, count = 0; y < 20; y++)
	{
		grid[y].resize(20);
		for (unsigned int x = 0; x < 20; x++, count++)
		{
			grid[y][x] = std::atoi(splitGrid[count].c_str());
		}
	}

	unsigned long long max = 0;

	for (unsigned int y = 0; y < 20; y++)
	{
		for (unsigned int x = 0; x < 20; x++)
		{
			// Product to the right
			if (x + 3 < 20)
			{
				unsigned long long current = grid[y][x] * grid[y][x + 1] * grid[y][x + 2] * grid[y][x + 3];

				if (current > max)
				{
					max = current;
				}
			}

			// Product to the bottom
			if (y + 3 < 20)
			{
				unsigned long long current = grid[y][x] * grid[y + 1][x] * grid[y + 2][x] * grid[y + 3][x];

				if (current > max)
				{
					max = current;
				}
			}

			// Product right bottom diagonal
			if (x + 3 < 20 && y + 3 < 20)
			{
				unsigned long long current = grid[y][x] * grid[y + 1][x + 1] * grid[y + 2][x + 2] * grid[y + 3][x + 3];

				if (current > max)
				{
					max = current;
				}
			}

			// Product left bottom diagonal
			if (static_cast<int>(x) - 3 >= 0 && y + 3 < 20)
			{
				unsigned long long current = grid[y][x] * grid[y + 1][x - 1] * grid[y + 2][x - 2] * grid[y + 3][x - 3];

				if (current > max)
				{
					max = current;
				}
			}
		}
	}

	return max;
}

unsigned long long highlyDivisibleTriangularNumber()
{
	unsigned int minDivisors = 500;
	unsigned long long current = 1;

	while (true)
	{
		unsigned long long triangleNumber = 0;
		for (unsigned int i = 1; i <= current; i++)
		{
			triangleNumber += i;
		}

		unsigned int currentDivisors = 0;
		for (unsigned int i = 1; i <= sqrt(triangleNumber); i++)
		{
			if (triangleNumber % i == 0)
			{
				currentDivisors += 2;
			}
		}

		if (currentDivisors > minDivisors)
		{
			return triangleNumber;
		}

		current++;
	}
}

std::string largeSum()
{
	std::ifstream input("Inputs/Problem 13.txt");
	if (!input.is_open())
	{
		std::cout << "Failed to open input for Problem 13." << std::endl;
		return "";
	}

	std::vector<std::string> numbers;

	std::string line;
	while (std::getline(input, line))
	{
		std::reverse(line.begin(), line.end());
		numbers.push_back(line);
	}

	std::string result = "";

	unsigned int carryOver = 0;
	for (unsigned int i = 0; i < 50; i++)
	{
		unsigned int current = carryOver;
		for (int j = 0; j < 100; j++)
		{
			current += numbers[j][i] - '0';
		}

		if (current >= 10)
		{
			carryOver = current / 10;
		}

		result += std::to_string(current % 10);
	}

	result += std::to_string(carryOver);

	std::reverse(result.begin(), result.end());

	return result.substr(0, 10);
}

unsigned int longestCollatzSequence()
{
	unsigned long long maxCount = 0;
	unsigned int maxNumber = 0;

	for (unsigned int i = 1; i < 1000000; i++)
	{
		unsigned long long current = i;
		unsigned long long currentCount = 0;

		while (current != 1)
		{
			if (current % 2 == 0)
			{
				current = current / 2;
			}
			else
			{
				current = current * 3 + 1;
			}

			currentCount++;
		}

		if (currentCount > maxCount)
		{
			maxCount = currentCount;
			maxNumber = i;
		}
	}

	return maxNumber;
}

unsigned long long latticePaths()
{
	unsigned int gridSize = 20;

	return factorial(gridSize + gridSize) / (factorial(gridSize) * factorial(gridSize));
}

std::string powerSum()
{
	BigInt myInt(2);

	BigInt product = BigMath::Pow(myInt, 1000);

	auto digits = product.GetDigits();

	unsigned long long sum = 0;

	for (unsigned int i = 0; i < digits.size(); i++)
	{
		sum += digits[i];
	}

	return std::to_string(sum);
}

unsigned long long numberLetterCounts()
{
	unsigned long long total = 0;
	for (unsigned int i = 1; i <= 1000; i++)
	{
		std::string current = "";

		if (i <= 20)
		{
			current = NumbersToWords[i];
		}
		else if (i < 100)
		{
			current = NumbersToWords[i / 10 * 10];

			if (i % 10 != 0)
			{
				
				current += NumbersToWords[i % 10];
			}
		}
		else if (i < 1000)
		{
			current = NumbersToWords[i / 100] + NumbersToWords[100];
			
			if (i % 100 != 0)
			{
				current += "and";
				
				if (i % 100 <= 20)
				{
					current += NumbersToWords[i % 100];
				}
				else
				{
					current += NumbersToWords[i % 100 / 10 * 10];

					if (i % 10 != 0)
					{
						current += NumbersToWords[i % 10];
					}
				}
			}
		}
		else
		{
			current = NumbersToWords[i / 1000] + NumbersToWords[i];
		}

		total += current.length();
	}

	return total;
}

unsigned long long maximumPathSum()
{

}

int main()
{
	std::cout << numberLetterCounts() << std::endl;

	system("pause");
	return 0;
}