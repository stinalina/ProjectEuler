/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <vector>
#include <math.h>

static long long SolveP10() //Nutze Sieb des Erastothenes
{
	int size = 2000000;
	long long result = 0LL;

	std::vector<bool> isPrim(size, true); 

	for (int i = 2; i < sqrt(size); i++)
	{
		for (int j = i*i; j < size; j += i)
			isPrim.at(j) = false; 
	}

 	for (int i = 2; i < size; i++)
		if (isPrim.at(i)) result += i;

	return result; 
}