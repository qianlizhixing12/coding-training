#include <vector>
#include <unordered_map>

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
  TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int start, int end,
                int &cur, unordered_map<int, int> &cache) {
    if (start > end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[cur]);
    int mid = cache[preorder[cur++]];
    root->left = dfs(preorder, inorder, start, mid - 1, cur, cache);
    root->right = dfs(preorder, inorder, mid + 1, end, cur, cache);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int cur = 0;
    unordered_map<int, int> cache;
    for (int i = 0; i < inorder.size(); i++) {
      cache[inorder[i]] = i;
    }
    return dfs(preorder, inorder, 0, inorder.size() - 1, cur, cache);
  }
};