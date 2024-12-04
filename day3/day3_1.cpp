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

    ifstream input(argv[1]);

    regex pattern(R"(mul\(\s*([+-]?\d+)\s*,\s*([+-]?\d+)\s*\))");
    long sum = 0;

    for (string line; getline(input, line);)
    {
        smatch matches;
        auto words_begin = sregex_iterator(line.begin(), line.end(), pattern);
        auto words_end = sregex_iterator();

        for (auto it = words_begin; it != words_end; ++it)
        {
            smatch match = *it;
            sum += stoi(match[1].str()) * stoi(match[2].str());
        }
    }

    input.close();

    cout << sum << endl;

    return 0;
}
