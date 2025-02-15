/*******************************************************
              Problem 15  Lattice paths
Starting in the top left corner of a 2×2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner. How
many such routes are there through a 20×20 grid?
*******************************************************/

// 到达网格的路径数 https://projecteuler.net/problem=15

#include <iostream>
#include <vector>

using namespace std;

long long int getRoutes(int num);
long long int getRoutes_(int num);

int main(int argc, char *argv[]) {
  //   cout << getRoutes(2) << endl;
  //   cout << getRoutes(20) << endl;
  cout << getRoutes_(2) << endl;
  cout << getRoutes_(20) << endl;
  return 0;
}

long long int getRoutes(int num) {
  num++;
  // 动态规划
  vector<vector<long long int>> dp(num, vector<long long int>(num, 0));
  // 初始化
  for (int i = 0; i < num; i++) {
    dp[0][i] = 1;
    dp[i][0] = 1;
  }
  for (int i = 1; i < num; i++) {
    for (int j = 1; j < num; j++) {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }
  return dp[num - 1][num - 1];
}

long long int getRoutes_(int num) {
  num++;
  // 动态规划, 一维数组
  vector<long long int> dp(num, 1);
  for (int i = 1; i < num; i++) {
    for (int j = 1; j < num; j++) {
      dp[j] += dp[j - 1];
    }
  }
  return dp[num - 1];
}