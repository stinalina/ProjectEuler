#include <iostream>

#include "Timer.h"
#include "Problems.h"

int main()
{
	Timer t;
	t.Run();
	std::cout << "Result: " << SolveP15() << "\n";
	t.Stop();
}
