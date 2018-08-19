#pragma once

#include <vector>

namespace Problems
{
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

	unsigned int getDaysForMonth(unsigned int month, bool leapYear)
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		else if (month == 2)
		{
			return (leapYear ? 29 : 28);
		}
		else
		{
			return 31;
		}
	}

	unsigned long long countingSundays()
	{
		unsigned long long count = 0;
		Weekday currentWeekday = Monday;

		for (unsigned int year = 1900; year < 2001; year++)
		{
			bool leapYear = (year % 4 == 0 && (year % 100 == 0 ? year % 400 == 0 : true));

			for (unsigned int month = 1; month <= 12; month++)
			{
				if (year > 1900 && currentWeekday == Sunday)
				{
					count++;
				}

				for (unsigned int day = 1; day <= getDaysForMonth(month, leapYear); day++)
				{
					if (currentWeekday == Sunday)
					{
						currentWeekday = Monday;
					}
					else
					{
						currentWeekday = static_cast<Weekday>(static_cast<int>(currentWeekday) + 1);
					}
				}
			}
		}

		return count;
	}
}