#pragma once

#include <vector>
#include <algorithm>
#include <string>

class BigInt
{
public:
	BigInt()
	{

	}

	BigInt(int i)
		:BigInt(static_cast<long long>(i))
	{
		
	}

	BigInt(long i)
		:BigInt(static_cast<long long>(i))
	{

	}

	BigInt(long long i)
	{
		while (i > 0)
		{
			mDigits.push_back(i % 10);
			i /= 10;
		}
	}

	BigInt(std::string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			mDigits.push_back(s[i] - '0');
		}
	}

	BigInt& operator=(const int other)
	{
		return *this = static_cast<long long>(other);
	}

	BigInt& operator=(const long other)
	{
		return *this = static_cast<long long>(other);
	}

	BigInt& operator=(const long long other)
	{
		mDigits.clear();

		long long buffer = other;

		while (buffer > 0)
		{
			mDigits.push_back(buffer % 10);
			buffer /= 10;
		}

		return *this;
	}

	BigInt& operator=(const BigInt& other)
	{
		if (this != &other) 
		{ 
			mDigits = other.mDigits;
		}

		return *this;
	}

	BigInt operator+(const BigInt& other)
	{
		BigInt ret;

		unsigned int otherSize = other.mDigits.size();
		unsigned int thisSize = mDigits.size();

		unsigned int size = std::max(otherSize, thisSize);

		unsigned int carryOver = 0;
		for (unsigned int i = 0; i < size; i++)
		{
			unsigned int current = carryOver;

			if (otherSize > i)
			{
				current += other.mDigits[i];
			}
			if (thisSize > i)
			{
				current += mDigits[i];
			}

			if (current > 9)
			{
				carryOver = current / 10;
			}
			else
			{
				carryOver = 0;
			}

			ret.mDigits.push_back(current % 10);
		}

		while (carryOver > 0)
		{
			unsigned int current = carryOver;

			if (current > 9)
			{
				carryOver = current / 10;
			}
			else
			{
				carryOver = 0;
			}

			ret.mDigits.push_back(current % 10);
		}

		return ret;
	}

	BigInt operator+(const int other)
	{
		return *this + static_cast<long long>(other);
	}

	BigInt operator+(const long other)
	{
		return *this + static_cast<long long>(other);
	}

	BigInt operator+(const long long other)
	{
		BigInt ret;

		unsigned int digit = 0;
		unsigned int i = other;
		unsigned int carryOver = 0;
		while (i > 0)
		{
			unsigned int current = i % 10 + carryOver;

			if (mDigits.size() > digit)
			{
				current += mDigits[digit];
			}

			if (current > 9)
			{
				carryOver = current / 10;
			}
			else
			{
				carryOver = 0;
			}

			ret.mDigits.push_back(current % 10);

			i /= 10;
			digit++;
		}

		while (digit < mDigits.size())
		{
			unsigned int current = mDigits[digit] + carryOver;

			if (current > 9)
			{
				carryOver = current / 10;
			}
			else
			{
				carryOver = 0;
			}

			ret.mDigits.push_back(current % 10);
			digit++;
		}

		while (carryOver > 0)
		{
			unsigned int current = carryOver;

			if (current > 9)
			{
				carryOver = current / 10;
			}
			else
			{
				carryOver = 0;
			}

			ret.mDigits.push_back(current % 10);
		}

		return ret;
	}

	BigInt& operator++(int)
	{
		unsigned int digit = 0;
		unsigned int carryOver = 0;

		mDigits[digit]++;

		if (mDigits[digit] > 9)
		{
			carryOver = mDigits[digit] / 10;
			mDigits[digit] = mDigits[digit] % 10;
		}

		digit++;

		while (carryOver > 0)
		{
			unsigned int current = carryOver;

			if (mDigits.size() > digit)
			{
				current += mDigits[digit];
			}

			if (current > 9)
			{
				carryOver = current / 10;
			}
			else
			{
				carryOver = 0;
			}

			if (mDigits.size() > digit)
			{
				mDigits[digit] = current % 10;
			}
			else
			{
				mDigits.push_back(current % 10);
			}

			digit++;
		}

		return *this;
	}

	BigInt operator*(const long long other)
	{
		
	}

	BigInt operator*(const BigInt other)
	{
		std::vector<BigInt> results;

		for (int i = other.mDigits.size() - 1; i >= 0; i--)
		{
			BigInt currentNumber;
			unsigned int carryOver = 0;

			for (unsigned int j = 0; j < mDigits.size(); j++)
			{
				unsigned int current = other.mDigits[i] * mDigits[j] + carryOver;

				if (current > 9)
				{
					carryOver = current / 10;
				}
				else
				{
					carryOver = 0;
				}

				currentNumber.mDigits.push_back(current % 10);
			}

			while (carryOver > 0)
			{
				unsigned int current = carryOver;

				if (current > 9)
				{
					carryOver = current / 10;
				}
				else
				{
					carryOver = 0;
				}

				currentNumber.mDigits.push_back(current % 10);
			}

			for (unsigned int j = 0; j < i; j++)
			{
				currentNumber.mDigits.insert(currentNumber.mDigits.begin(), 0);
			}

			results.push_back(currentNumber);
		}

		BigInt ret;
		for (unsigned int i = 0; i < results.size(); i++)
		{
			ret = ret + results[i];
		}

		return ret;
	}

	std::string to_string()
	{
		std::string s = "";

		for (int i = mDigits.size() - 1; i >= 0; i--)
		{
			s += std::to_string(mDigits[i]);
		}

		return s;
	}

	std::vector<unsigned short> GetDigits()
	{
		return mDigits;
	}

private:
	std::vector<unsigned short> mDigits;
};