#pragma once

#include <map>
#include <string>

std::map<unsigned int, std::string> NumbersToWords =
{
	{ 0, "zero" },
	{ 1, "one" },
	{ 2, "two" },
	{ 3, "three" },
	{ 4, "four" },
	{ 5, "five" },
	{ 6, "six" },
	{ 7, "seven" },
	{ 8, "eight" },
	{ 9, "nine" },
	{ 10, "ten" },
	{ 11, "eleven" },
	{ 12, "twelve" },
	{ 13, "thirteen" },
	{ 14, "fourteen" },
	{ 15, "fifteen" },
	{ 16, "sixteen" },
	{ 17, "seventeen" },
	{ 18, "eighteen" },
	{ 19, "nineteen" },
	{ 20, "twenty" },
	{ 30, "thirty" },
	{ 40, "forty" },
	{ 50, "fifty" },
	{ 60, "sixty" },
	{ 70, "seventy" },
	{ 80, "eighty" },
	{ 90, "ninety" },
	{ 100, "hundred" },
	{ 1000, "thousand" }
};

namespace Problems
{
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
}