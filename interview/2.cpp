#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 输入一组(10个)32位整数，每8位累加后取模，返回取模后统计小于指定值的最大统计值
 */
int main() {
  long comp;
  long div;
  long val;
  cin >> comp >> div;
  vector<int> cache(comp, 0);

  for (int i = 0; i < 10; i++) {
    cin >> val;
    long sum = ((val & 0xFF000000) >> 24) + ((val & 0x00FF0000) >> 16) +
               ((val & 0x0000FF00) >> 8) + (val & 0x000000FF);
    long mod = (sum % div);
    if (mod < comp) {
      cache[mod]++;
    }
  }

  cout << *max_element(cache.begin(), cache.end()) << endl;

  return 0;
}