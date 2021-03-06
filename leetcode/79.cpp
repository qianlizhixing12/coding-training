#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int x = 0; x < board.size(); x++) {
      for (int y = 0; y < board[x].size(); y++) {
        if (dfs(board, word, 0, x, y)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>> &board, string word, int pos, int x, int y) {
    if (pos >= word.size()) {
      return true;
    }
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() ||
        word[pos] != board[x][y]) {
      return false;
    }
    board[x][y] = '@';
    bool rst = dfs(board, word, pos + 1, x, y - 1) ||
               dfs(board, word, pos + 1, x, y + 1) ||
               dfs(board, word, pos + 1, x - 1, y) ||
               dfs(board, word, pos + 1, x + 1, y);
    board[x][y] = word[pos];
    return rst;
  }
};