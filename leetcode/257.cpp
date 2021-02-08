#include <vector>
#include <string>

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
private:
  vector<string> result;
  void dfs(TreeNode *root, string path) {
    if (root == nullptr) {
      return;
    }
    if (path != "") {
      path = path + "->" + to_string(root->val);
    } else {
      path = to_string(root->val);
    }
    if (root->left == nullptr && root->right == nullptr) {
      result.push_back(path);
    }
    dfs(root->left, path);
    dfs(root->right, path);
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    result.clear();
    dfs(root, "");
    return result;
  }
};