/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

static int SolveP5()
{
	bool found = false;

	for (int i = 2520; true; i += 20) //2520 can be divided by 20!
	{
		for (int j = 2; j < 20; j++)
		{
			if (i % j == 0) found = true;
			else { found = false; break; }
		}
		
		if (found) return i;
	}

	return 0;
}