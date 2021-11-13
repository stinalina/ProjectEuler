/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <map>

enum Numbers { zero, one, two, three, four, five, six, seven, eight, nine,
			ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,
			twenty, thirty=30, forty=40, fifty=50, sixty=60, seventy=70, eighty=80, ninety=90, hundred=100};
				
std::map<Numbers, size_t> numberLetterCount{
	{Numbers::one,		3},
	{Numbers::two,		3},
	{Numbers::three,	5},
	{Numbers::four,		4},
	{Numbers::five,		4},
	{Numbers::six,		3},
	{Numbers::seven,	5},
	{Numbers::eight,	5},
	{Numbers::nine,		4},
	{Numbers::ten,		3},
	{Numbers::eleven,	6},
	{Numbers::twelve,	6},
	{Numbers::thirteen, 8},
	{Numbers::fourteen, 8},
	{Numbers::fifteen,	7},
	{Numbers::sixteen,	7},
	{Numbers::seventeen, 9},
	{Numbers::eighteen, 8},
	{Numbers::nineteen, 8},
	{Numbers::twenty,	6},
	{Numbers::thirty,	6},
	{Numbers::forty,	5},
	{Numbers::fifty,	5},
	{Numbers::sixty,	5},
	{Numbers::seventy,	7},
	{Numbers::eighty,	6},
	{Numbers::ninety,	6},
	{Numbers::hundred,	7}
};

static unsigned int SolveP17()
{
	unsigned int result = 0; 
	
	// Calculate 1 - 9
	unsigned int oneToNine = 0;
	for (int i = 1; i < 10; i++)
		oneToNine += numberLetterCount[Numbers(i)];

	// Calculate 11 - 19
	unsigned int elvToTwelv = 0;
	for (int i = 11; i < 20; i++)
		elvToTwelv += numberLetterCount[Numbers(i)];

	// Calculate 20 - 99
	unsigned int twentyTo99 = 0;
	for (int i = 20; i < 100; i+=10)
	{
		twentyTo99 += 10 * numberLetterCount[Numbers(i)];
		twentyTo99 += oneToNine;
	}

	unsigned int oneTo99 = oneToNine + numberLetterCount[Numbers(10)] + elvToTwelv + twentyTo99;

	// Calculate up to 999
	for (int i = 1; i < 10; i++)
	{
		result += 100 * numberLetterCount[Numbers(i)];
		result += 100 * numberLetterCount[Numbers(100)];
		result += 99 * 3; //"and"
		result += oneTo99;
	}

	return result + oneTo99 + 11; // one thousend = 3 + 8
}