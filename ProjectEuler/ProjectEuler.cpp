// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Problem 1.h"
#include "Problem 2.h"
#include "Problem 3.h"
#include "Problem 4.h"
#include "Problem 5.h"
#include "Problem 6.h"
#include "Problem 7.h"
#include "Problem 8.h"
#include "Problem 10.h"
#include "Problem 11.h"
#include "Problem 12.h"
#include "Problem 13.h"
#include "Problem 14.h"
#include "Problem 15.h"
#include "Problem 16.h"
#include "Problem 17.h"
#include "Problem 18.h"
#include "Problem 19.h"


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
	std::cout << Problems::maximumPathSum() << std::endl;

	system("pause");
	return 0;
}