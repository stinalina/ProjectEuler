/*
* Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

static unsigned int SolveP2()
{
	unsigned int result = 0;

	unsigned int fibLast = 1;
	unsigned int fibNext = 2;
	unsigned int tmp;

	while (fibNext < 4000000)
	{
		if (fibNext % 2 == 0) result += fibNext;

		tmp = fibNext;
		fibNext += fibLast;
		fibLast = tmp;
	}

	return result;
}