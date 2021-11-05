#include <stdio.h>

/*
* The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Alle natürlichen Zahlen lassen sich so weit runterbrechen, dass sie nur noch aus Primzahlen bestehen
*/

static int SolveP3()
{
	int i = 2;
	_int64 n = 600851475143;

	while (n > 1)
	{
		if (n % i == 0)
		{
			n /= i;
			//i--;  // skip this for big numbers
		}
		i++;
	}
			
	return i;
}