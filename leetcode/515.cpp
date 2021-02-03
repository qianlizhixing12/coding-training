#include <vector>
#include <queue>
#include <climits>

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
  vector<int> largestValues(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }
    queue<TreeNode *> cache;
    cache.push(root);
    while (!cache.empty()) {
      int size = cache.size();
      int max = INT_MIN;
      for (int i = 0; i < size; i++) {
        TreeNode *temp = cache.front();
        cache.pop();
        max = max >= temp->val ? max : temp->val;
        if (temp->left != nullptr) {
          cache.push(temp->left);
        }
        if (temp->right != nullptr) {
          cache.push(temp->right);
        }
      }
      result.push_back(max);
    }
    return result;
  }
};