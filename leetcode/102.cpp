#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    queue<TreeNode *> cache;
    cache.push(root);
    while (!cache.empty()) {
      int size = cache.size();
      vector<int> level(size);
      for (int i = 0; i < size; i++) {
        TreeNode *temp = cache.front();
        cache.pop();
        level[i] = temp->val;
        if (temp->left != nullptr) {
          cache.push(temp->left);
        }
        if (temp->right != nullptr) {
          cache.push(temp->right);
        }
      }
      result.push_back(level);
    }
    return result;
  }
};