#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isValid(const string &word, const string &puzzle, char head) {
  bool headExist = false;
  int pos = 0;
  for (auto c : word) {
    if (c == head) {
      headExist = true;
    }
    if (pos >= 7 || c < puzzle[pos]) {
      return false;
    }
    while (c != puzzle[pos++]) {
      if (pos >= 7) {
        return false;
      }
    }
  }
  return headExist;
}

class Solution1 {
public:
  // 排序去重 哈希计次，对比
  vector<int> findNumOfValidWords(vector<string> &words,
                                  vector<string> &puzzles) {
    vector<int> help(26, 0);
    // 排序去重words
    unordered_map<string, int> nwords;
    for (auto &word : words) {
      for (auto &c : word) {
        help[c - 'a']++;
      }
      string s;
      for (int i = 0; i < 26; i++) {
        if (help[i] > 0) {
          s += i + 'a';
          help[i] = 0;
        }
      }
      if (s.size() <= 7) {
        nwords[s]++;
      }
    }
    // 排序puzzles
    unordered_map<string, vector<int>> npuzzles;
    for (int k = 0; k < puzzles.size(); k++) {
      string puzzle = puzzles[k];
      for (auto &c : puzzle) {
        help[c - 'a']++;
      }
      string s;
      for (int i = 0; i < 26; i++) {
        if (help[i] > 0) {
          s += i + 'a';
          help[i] = 0;
        }
      }
      s += puzzle[0];
      npuzzles[s].emplace_back(k);
    }
    // 循环查找
    vector<int> rst(puzzles.size());
    for (auto &puzzle : npuzzles) {
      int count = 0;
      for (auto &info : nwords) {
        count +=
            isValid(info.first, puzzle.first.substr(0, puzzle.first.size() - 1),
                    puzzle.first[puzzle.first.size() - 1])
                ? info.second
                : 0;
      }
      for (int id : puzzle.second) {
        rst[id] = count;
      }
    }
    return rst;
  }
};

class Solution2 {
public:
  // 排序去重 哈希计次，对比  运用系统排序和去重功能
  vector<int> findNumOfValidWords(vector<string> &words,
                                  vector<string> &puzzles) {
    // 排序去重words, nwords内容格式 word(去重且排序)-->count
    unordered_map<string, int> nwords;
    for (auto &word : words) {
      sort(word.begin(), word.end());
      word.erase(unique(word.begin(), word.end()), word.end());
      if (word.size() <= 7) {
        nwords[word]++;
      }
    }
    // 排序puzzles(本身不重复) npuzzles内容格式 puzzle(排序)+首字符-->索引数组
    unordered_map<string, vector<int>> npuzzles;
    for (int k = 0; k < puzzles.size(); k++) {
      string puzzle = puzzles[k];
      char c = puzzle[0];
      sort(puzzle.begin(), puzzle.end());
      npuzzles[puzzle + c].emplace_back(k);
    }
    // 循环查找
    vector<int> rst(puzzles.size());
    for (auto &puzzle : npuzzles) {
      int count = 0;
      for (auto &info : nwords) {
        count +=
            isValid(info.first, puzzle.first.substr(0, puzzle.first.size() - 1),
                    puzzle.first[puzzle.first.size() - 1])
                ? info.second
                : 0;
      }
      for (int id : puzzle.second) {
        rst[id] = count;
      }
    }
    return rst;
  }
};

class Solution3 {
public:
  struct TrieNode {
    int frequency = 0;
    TrieNode *child[26];

    TrieNode() {
      for (int i = 0; i < 26; ++i) {
        child[i] = nullptr;
      }
    }
  };

  void add(const string &word, TrieNode *root) {
    TrieNode *cur = root;
    for (char ch : word) {
      if (!cur->child[ch - 'a']) {
        cur->child[ch - 'a'] = new TrieNode();
      }
      cur = cur->child[ch - 'a'];
    }
    ++cur->frequency;
  };

  int find(const string &puzzle, TrieNode *root, char first, int pos) {
    if (!root) {
      return 0;
    }

    if (pos == 7) {
      return root->frequency;
    }

    int ret = find(puzzle, root->child[puzzle[pos] - 'a'], first, pos + 1);

    // 当 puzzle[pos] 不为首字母时，可以不选择第 pos 个字母
    if (puzzle[pos] != first) {
      ret += find(puzzle, root, first, pos + 1);
    }

    return ret;
  }

  // 将words生成字典树，进一步减少循环次数
  vector<int> findNumOfValidWords(vector<string> &words,
                                  vector<string> &puzzles) {
    // 排序去重words, nwords内容格式 word(去重且排序)-->count
    TrieNode *root = new TrieNode();
    for (string &word : words) {
      sort(word.begin(), word.end());
      word.erase(unique(word.begin(), word.end()), word.end());
      if (word.size() <= 7) {
        add(word, root);
      }
    }
    // 循环查找
    vector<int> rst;
    for (auto &puzzle : puzzles) {
      char first = puzzle[0];
      sort(puzzle.begin(), puzzle.end());
      rst.emplace_back(find(puzzle, root, first, 0));
    }
    return rst;
  }
};

class Solution4 {
public:
  // 状态压缩，巧妙用二进制表示一个字符多次出现的字符串
  vector<int> findNumOfValidWords(vector<string> &words,
                                  vector<string> &puzzles) {
    // words二进制唯一表示
    unordered_map<int, int> nwords;
    for (string &word : words) {
      int mask = 0;
      for (char c : word) {
        mask |= 1 << (c - 'a');
      }
      if (__builtin_popcount(mask) <= 7) {
        nwords[mask]++;
      }
    }
    // 循环计算
    vector<int> rst;
    for (string &puzzle : puzzles) {
      int total = 0;
      int mask = 0;
      for (int i = 1; i < 7; ++i) {
        mask |= (1 << (puzzle[i] - 'a'));
      }
      int subset = mask;
      do {
        //保证首字符必须存在
        int s = subset | (1 << (puzzle[0] - 'a'));
        if (nwords.count(s)) {
          total += nwords[s];
        }
        subset = (subset - 1) & mask;
      } while (subset != mask);
    }
    return rst;
  }
};

int main() {
  vector<string> words = {"aaaa", "asas",  "able",  "ability",
                          "actt", "actor", "access"};
  vector<string> puzzles = {"aboveyz", "abrodyz", "abslute",
                            "absoryz", "actresz", "gaswxyz"};
  Solution1().findNumOfValidWords(words, puzzles);
  return 0;
}