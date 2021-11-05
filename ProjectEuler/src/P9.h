/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <vector>

static int SolveP9()
{
	for (unsigned int i = 100; i < 500; i++)
	{
		for (unsigned int j = 100; j < 500; j++)
		{
			if (i == j) continue;

			for (unsigned int k = 100; k < 500; k++)
			{
				if ((i + j + k) == 1000)
					if (k*k == i*i + j*j)
						return i * j * k;
			}
		}
	}

	return 0;
}