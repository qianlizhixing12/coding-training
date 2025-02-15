/*******************************************************
              Problem 17  Number letter counts
If the numbers 1 to 5 are written out in words: one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total. If all the numbers
from 1 to 1000 (one thousand) inclusive were written out in words, how many
letters would be used? NOTE: Do not count spaces or hyphens. For example, 342
(three hundred and forty-two) contains 23 letters and 115 (one hundred and
fifteen) contains 20 letters. The use of "and" when writing out numbers is in
compliance with British usage.
*******************************************************/

// 数字英文写法包含的字母 https://projecteuler.net/problem=17

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getNumberLetterCounts();

int main(int argc, char *argv[]) {
  cout << getNumberLetterCounts() << endl;
  return 0;
}

int getNumberLetterCounts() {
  // 0-19
  vector<int> single = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4,
                        3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
  // 0, 10, 20, 30 ,40 ... 90
  vector<int> tens = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
  int hundred = 7;
  int And = 3;
  int thousand = 8;
  int sum = 0;
  // 0-999
  for (int i = 0; i < 10; i++) {
    int pre = (i != 0 ? single[i] + hundred + And : 0);
    // 0-19
    for (int j = 1; j < 20; j++) {
      sum += pre + single[j];
    }
    // 20-99
    for (int j = 20; j < 100; j++) {
      sum += pre + single[j % 10] + tens[j / 10];
    }
    // 百
    sum += (i != 0 ? single[i] + hundred : 0);
  }
  // 1000
  sum += 3 + thousand;
  return sum;
}