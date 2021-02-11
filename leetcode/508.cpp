#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int dfs(TreeNode *root, unordered_map<int, int> &cache) {
    if (root == NULL) {
      return 0;
    }
    int l = dfs(root->left, cache);
    int r = dfs(root->right, cache);
    int sum = l + r + root->val;
    if (cache.find(sum) == cache.end()) {
      cache[sum] = 0;
    }
    cache[sum]++;
    return sum;
  }

public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    if (root == NULL) {
      return vector<int>();
    }
    unordered_map<int, int> cache;
    dfs(root, cache);
    unordered_map<int, vector<int>> help;
    for (unordered_map<int, int>::iterator it = cache.begin();
         it != cache.end(); it++) {
      if (help.find(it->second) == help.end()) {
        help[it->second] = vector<int>();
      }
      help[it->second].push_back(it->first);
    }
    return max_element(help.begin(), help.end())->second;
  }
};