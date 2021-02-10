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
  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int start,
                  int end, unordered_map<int, int> &cache, int &cur) {
    if (start > end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(postorder[cur]);
    int mid = cache[postorder[cur--]];
    root->right = build(inorder, postorder, mid + 1, end, cache, cur);
    root->left = build(inorder, postorder, start, mid - 1, cache, cur);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int cur = postorder.size() - 1;
    unordered_map<int, int> cache;

    for (int i = 0; i < inorder.size(); i++) {
      cache[inorder[i]] = i;
    }

    return build(inorder, postorder, 0, inorder.size() - 1, cache, cur);
  }
};