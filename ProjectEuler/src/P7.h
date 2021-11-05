/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

static int SolveP7()
{
	int i, counter = 6;
	bool isPrim = false;

	for (i = 14; counter < 10001 ;i++)
	{
		isPrim = true;

		for (int j = 2; j <= (i / 2); j++)
		{
			if ((i != j) && (i % j == 0)) { isPrim = false; break; }
		}

		if (isPrim) counter++;
	}

	return i-1;
}