/*
n! means n * (n − 1) * ... * 3 * 2 * 1

For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <string>

static double Fac(double n)
{
	if (n > 1)
		return n*Fac(n - 1);

	return 1.0;
}

static int SolveP20()
{
	int result = 0;
	double n = Fac(100.0);
	std::string s = std::to_string(n);

	for (char c : s)
	{
		if (c == '.') break;
		result += c - 48;
	}	

	return result; // Should be 648
}