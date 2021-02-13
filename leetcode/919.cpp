#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {
private:
  TreeNode *root = NULL;
  queue<TreeNode *> last;

  void bfs(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    last.push(root);
    while (!last.empty()) {
      bool full = true;
      for (int i = 0; i < last.size(); i++) {
        TreeNode *parent = last.front();
        if (parent->left == NULL || parent->right == NULL) {
          if (parent->left != NULL) {
            last.push(parent->left);
          }
          full = false;
          break;
        }
        last.pop();
        last.push(parent->left);
        last.push(parent->right);
      }
      if (!full) {
        break;
      }
    }
  }

public:
  CBTInserter(TreeNode *root) : root(root) { bfs(root); }

  int insert(int v) {
    TreeNode *cur = new TreeNode(v);
    TreeNode *parent = last.front();
    last.push(cur);
    if (parent->left == NULL) {
      parent->left = cur;
      return parent->val;
    }
    last.pop();
    parent->right = cur;
    return parent->val;
  }

  TreeNode *get_root() { return root; }
};