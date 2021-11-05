/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <string>

static int SolveP4()
{
	int n = 0;

	for (int x = 999; x > 900; x--)
	{
		for (int y = 999; y > 900; y--) 
		{
			n = x * y;

			//check for palindrome
			std::string tmp = std::to_string(n);
			int size = tmp.size();
			if (tmp.at(0) == tmp.at(size - 1) && tmp.at(1) == tmp.at(size - 2) && tmp.at(2) == tmp.at(size - 3))
				return x*y;
		}
	}
	return n;
}