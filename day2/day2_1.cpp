#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    if (argc < 2)
    {
        cout << "Path to input file is needed, try again." << endl;
        return -1;
    }

    int safecount = 0;

    ifstream input(argv[1]);

    for (string line; getline(input, line);)
    {
        stringstream stream(line);
        string str;
        vector<int> vec;

        while (getline(stream, str, ' '))
        {
            vec.push_back(stoi(str));
        }

        int safe = 1;
        if (vec[0] < vec[1])
        {
            // increasing
            for (size_t i = 0; i < vec.size() - 1; i++)
            {
                if (vec[i] >= vec[i + 1] || abs(vec[i] - vec[i + 1]) > 3)
                {
                    safe = 0;
                    break;
                }
            }
        }
        else if (vec[0] > vec[1])
        {
            // decreasing
            for (size_t i = 0; i < vec.size() - 1; i++)
            {
                if (vec[i] <= vec[i + 1] || abs(vec[i] - vec[i + 1]) > 3)
                {
                    safe = 0;
                    break;
                }
            }
        }
        else
        {
            // equality
            safe = 0;
        }

        safecount += safe;
    }

    input.close();

    cout << safecount << endl;

    return 0;
}
