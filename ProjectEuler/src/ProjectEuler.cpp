#include <iostream>

#include "Timer.h"
#include "Problems.h"

int main()
{
	Timer t;
	t.Run();
	std::cout << "Result: " << SolveP12() << "\n";
	t.Stop();
}