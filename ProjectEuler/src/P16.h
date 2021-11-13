/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <string>
#include <math.h>

static unsigned int SolveP16()
{
    double product = pow(2, 1000);
    std::string s = std::to_string(product);

    //int i = 0;
    //int result = 0;
    //while (i < s.size()-7) // Cut the 0's
    //{
    //    result += s[i] - 48;
    //    i++;
    //}

    int result = 0;
    for(char c : s)
    {
        if (c == '.') break;
        result += c - 48;
    }

    return result;
}