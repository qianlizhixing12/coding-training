/*******************************************************
              Problem 5  Smallest multiple
  2520 is the smallest number that can be divided by each of
the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible
by all of the numbers from 1 to 20?
*******************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int getSmallestMultiple(int num);

int main() {
  cout << getSmallestMultiple(10) << endl;
  //   cout << getSmallestMultiple(20) << endl;
  return 0;
}

int getSmallestMultiple(int num) {
  if (num <= 2) {
    return num;
  }
  vector<int> help = {2};
  for (int i = 3; i <= num; i++) {
    int tmp = i;
    int len = help.size();
    for (int j = 0; j < len; j++) {
      if (tmp == 1) {
        break;
      }
      if (tmp % help[j] == 0) {
        tmp /= help[j];
      }
    }
    if (tmp != 1) {
      help.emplace_back(tmp);
    }
  }
  int result = 1;
  for_each(help.begin(), help.end(), [&result](int n) { result *= n; });
  return result;
}