#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
  int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                   {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  void updateBoard_(vector<vector<char>> &board, int x, int y) {
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
    } else if (board[x][y] == 'E') {
      int countM = 0;
      for (int *d : dir) {
        int x_ = x + d[0];
        int y_ = y + d[1];
        if (x_ < 0 || y_ < 0 || x_ >= board.size() || y_ >= board[0].size()) {
          continue;
        }
        countM += (board[x_][y_] == 'M' ? 1 : 0);
      }
      if (countM == 0) {
        board[x][y] = 'B';
        for (int *d : dir) {
          int x_ = x + d[0];
          int y_ = y + d[1];
          if (x_ < 0 || y_ < 0 || x_ >= board.size() || y_ >= board[0].size()) {
            continue;
          }
          updateBoard_(board, x_, y_);
        }
      } else {
        board[x][y] = countM + '0';
      }
    }
  }

public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    updateBoard_(board, click[0], click[1]);
    return board;
  }
};

int main() {
  vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'M', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'}};
  vector<int> click = {3, 0};
  Solution().updateBoard(board, click);
  return 0;
}