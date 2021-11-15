/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:
*/

#include <vector>
#include <math.h>

static unsigned int SolveP18()
{
    std::vector<std::vector<int>> triangle;

    // Read the file
    {
        std::filesystem::path path = std::filesystem::current_path();
        path.append("src\\P18\\triangle.txt");
        std::ifstream stream(path); //input stream to read from file; constructor calls open()

        if (stream.is_open())
        {
            std::string line;
            while (getline(stream, line))
            {
                std::vector<int> digits;
                std::string digit = "";

                for (int i = 0; i < line.length(); i++) // '9', '5, ' ', '6', '4'
                {
                    digit.push_back(line[i]);

                    if (line[i] == ' ' || i == line.length() - 1)
                    {
                        digits.push_back(std::stoi(digit));
                        digit = "";
                    }
                }
                triangle.push_back(digits);
            }
        }
        else
            std::cout << "Can't find file!" << std::endl;

        stream.close();
    }

    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            triangle[i][j] += fmax(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    return triangle[0][0];
}