/*
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

static std::mutex s_ChainSizeMutex;
static int s_MaxChainSize = 0; 
static int s_StartingNumber = 0;

static void FindLongestChain(int startNumber)
{
	std::cout << "Thread " << std::this_thread::get_id() << " starts working.\n";

	for (int i = startNumber; i < startNumber + 100000; i++)
	{
		int currChainSize = 1; //including n and 1
		unsigned int n = i;
		while (n > 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3*n + 1;

			currChainSize++;
		}

		s_ChainSizeMutex.lock();
		if (currChainSize > s_MaxChainSize)
		{
			s_MaxChainSize = currChainSize;
			s_StartingNumber = i;
		}
		s_ChainSizeMutex.unlock();
	}
}

static int SolveP14()
{
	std::vector<std::thread> threads;
	threads.reserve(10);
	for (int i = 100000; i < 1000000; i += 100000) //10 threads
		threads.push_back(std::thread(FindLongestChain, i));

	for (auto& t : threads) // Wait for all threads to finish
	{
		std::cout << "Thread " << t.get_id() << " joined.\n";
		t.join();
	}
		
	return s_StartingNumber;
}