#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

int check_vec(vector<int> v)
{
    bool safe = true;
    if (v[0] < v[1])
    {
        // increasing
        for (size_t i = 0; i < v.size() - 1; i++)
        {
            if (v[i] >= v[i + 1] || abs(v[i] - v[i + 1]) > 3)
            {
                safe = false;
                break;
            }
        }
    }
    else if (v[0] > v[1])
    {
        // decreasing
        for (size_t i = 0; i < v.size() - 1; i++)
        {
            if (v[i] <= v[i + 1] || abs(v[i] - v[i + 1]) > 3)
            {
                safe = false;
                break;
            }
        }
    }
    else
    {
        // equality
        safe = false;
    }

    return safe;
}

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

        if (check_vec(vec))
        {
            safecount++;
        }
        else
        {
            // a bit of brute force never hurt anybody... right?
            for (size_t i = 0; i < vec.size(); i++)
            {
                vector<int> modified_vec = vec;
                modified_vec.erase(modified_vec.begin() + i);
                if (check_vec(modified_vec))
                {
                    safecount++;
                    break;
                }
            }
        }
    }

    input.close();

    cout << safecount << endl;

    return 0;
}
