/*
You are given the following information, but you may prefer to do some research for yourself.

	1 Jan 1900 was a Monday.
	Thirty days has September,
	April, June and November.
	All the rest have thirty-one,
	Saving February alone,
	Which has twenty-eight, rain or shine.
	And on leap years, twenty-nine.
	A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

static int SolveP19()
{
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int countingSundays = 0;
	int dayOfWeek = 2; // The 1st January in 1901 is a Thursday (2. day of week)

	for (int year = 1901; year <= 2000; year++)
	{
		bool isLabYear = (!(year % 4) && (year % 100)) || !(year % 400);
		months[1] = 28 + isLabYear;

		for(int month : months)
		{
			dayOfWeek += month % 7;

			if (dayOfWeek % 7 == 0)
				countingSundays++;
		}
	}

	return countingSundays;
}