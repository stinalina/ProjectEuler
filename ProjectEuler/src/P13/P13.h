/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

static unsigned long long SolveP13()
{
    std::vector<char> numbers[100];
    
    // Read the file
    std::filesystem::path path = std::filesystem::current_path(); 
    path.append("src\\P13\\numbers.txt");
    std::ifstream stream(path); //input stream to read from file; constructor calls open()

    if (stream.is_open())
    {
        std::string line;
        int pos = 0;

        while (getline(stream, line))
        {
            std::vector<char> digits;
            digits.reserve(50);

            for (int i = 0; i < 50; i++)
                digits.push_back(line.at(i));

            numbers[pos] = digits;
            pos++;
        }
    }
    else
        std::cout << "Can't find file!" <<  std::endl;

    stream.close();

    // Make the Calculation
    unsigned int result[50];
    int remainer = 0, columnResult = 0, sum = 0;

    for (int i = 49; i >= 0; i--)
    {
        columnResult = 0;
        for (int j = 0; j < 100; j++)
           columnResult += numbers[j].at(i) - 48;

        sum = columnResult + remainer;
        result[i] = sum % 10; //get the last digit
        remainer = sum / 10; //cut the last digit
    }

    // Figure out the first ten digits of the sum
    int i = 0;
    std::string s = std::to_string(remainer);
    while (s.size() < 10)
    {
        s.push_back(result[i] + 48);
        i++;
    }
     
    return std::stoull(s);
}