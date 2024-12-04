#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

long regexer(string str)
{
    long sum = 0;
    regex remove_pattern(R"(don't\(\)[\s\S]*?do\(\))");
    str = regex_replace(str, remove_pattern, "");

    regex pattern(R"(mul\(\s*([+-]?\d+)\s*,\s*([+-]?\d+)\s*\))");
    smatch matches;
    auto words_begin = sregex_iterator(str.begin(), str.end(), pattern);
    auto words_end = sregex_iterator();

    for (auto it = words_begin; it != words_end; ++it)
    {
        smatch match = *it;
        sum += stoi(match[1].str()) * stoi(match[2].str());
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cout << "Path to input file is needed, try again." << endl;
        return -1;
    }

    ifstream input(argv[1]);
    stringstream buffer;
    buffer << input.rdbuf();
    string text = buffer.str();

    input.close();

    cout << regexer(text) << endl;

    return 0;
}