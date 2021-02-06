#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  bool validTicTacToe(vector<string> &board) {
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 'X') {
          countX++;
        } else if (board[i][j] == 'O') {
          countO++;
        }
      }
    }
    // 第一个玩家总是放置'X'
    if (countX < countO) {
      return false;
    }
    // 玩家应该是轮流放置的
    if (countX - countO >= 2) {
      return false;
    }
    int winX = 0;
    int winO = 0;
    // 同行同列
    for (int i = 0; i < 3; i++) {
      if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
          board[0][i] == board[2][i]) {
        if (board[0][i] == 'X') {
          winX++;
        } else {
          winO++;
        }
      }
      if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
          board[i][0] == board[i][2]) {
        if (board[i][0] == 'X') {
          winX++;
        } else {
          winO++;
        }
      }
    }
    // 斜行斜列
    if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
        board[0][0] == board[2][2]) {
      if (board[0][0] == 'X') {
        winX++;
      } else {
        winO++;
      }
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] &&
        board[0][2] == board[2][0]) {
      if (board[0][2] == 'X') {
        winX++;
      } else {
        winO++;
      }
    }
    if (winX == winO && winX != 0) {
      return false;
    }
    if (winX > 2 || winO > 2) {
      return false;
    }
    if (winX > 0 && countX <= countO) {
      return false;
    }
    if (winO > 0 && countX > countO) {
      return false;
    }
    return true;
  }
};

int main() {
  // vector<string> board{"XXX", "OOX", "OOX"};
  // vector<string> board{"XOX", "O O", "XOX"};
  vector<string> board{"XXX", "   ", "OOO"};
  cout << Solution().validTicTacToe(board) << endl;
  return 0;
}