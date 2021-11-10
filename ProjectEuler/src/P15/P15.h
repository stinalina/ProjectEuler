/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid? -> Choose a subset of 20 elems from a set of 40 elems
*/

static unsigned long long binomCoefficient(int n, int k) // "n over k"
{
	unsigned long long result = 1ULL;
	for (unsigned int i = 1; i <= k; i++)
	{
		result *= k + i;
		result /= i;
	}
	return result;
}

static unsigned long long SolveP15()
{
	int gridSize = 20;
	return binomCoefficient(2*gridSize, gridSize);
}