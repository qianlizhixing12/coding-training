from typing import List


class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[i])):
                if self.dfs(board, word, 0, i, j):
                    return True
        return False

    def dfs(self, board: List[List[str]], word: str, pos: int, x: int,
            y: int) -> bool:
        if pos == len(word):
            return True
        if not (0 <= x < len(board)) or not (0 <= y < len(
                board[0])) or word[pos] != board[x][y]:
            return False
        board[x][y] = '#'
        exist = False
        for dir in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            if self.dfs(board, word, pos + 1, x + dir[0], y + dir[1]):
                exist = True
                break
        board[x][y] = word[pos]
        return exist
