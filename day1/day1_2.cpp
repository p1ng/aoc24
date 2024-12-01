#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream input("input1.txt");

  vector<int> v1 = {};
  vector<int> v2 = {};

  for (string line; getline(input, line);) {
    int val1 = stoi(line.substr(0, line.find("   ")));
    int val2 =
        stoi(line.substr(line.find("   "), line.length() - line.find("   ")));
    v1.push_back(val1);
    v2.push_back(val2);
  }

  input.close();

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  int score = 0;
  for (int val : v1) {
    int i = 0;
    for (int to_match : v2) {
      if (val == to_match) {
        i++;
      }
    }
    score += val * i;
  }

  cout << score << endl;

  return 0;
}
