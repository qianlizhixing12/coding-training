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

class Solution1 {
public:
  // def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
  //     if len(preorder) == 0:
  //         return None
  //     root = TreeNode(preorder[0])
  //     mid = inorder.index(preorder[0])
  //     root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
  //     root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
  //     return root
  /**
   * python的代码最好理解，但是每次迭代都创建了新数组
   * 模仿python的代码，传递左右边界，避免复制数组
   * 传递inorder的开始位置i1用于确认mid和i1的距离
   */
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> cache;
    for (int i = 0; i < inorder.size(); i++) {
      cache[inorder[i]] = i;
    }
    return buildTree_(cache, preorder, inorder, 0, preorder.size() - 1, 0,
                      inorder.size() - 1);
  }

  TreeNode *buildTree_(unordered_map<int, int> &cache, vector<int> &preorder,
                       vector<int> &inorder, int p1, int p2, int i1, int i2) {
    if (p1 > p2) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[p1]);
    int mid = cache[preorder[p1]];
    root->left = buildTree_(cache, preorder, inorder, p1 + 1, p1 + mid - i1, i1,
                            mid - 1);
    root->right = buildTree_(cache, preorder, inorder, p1 + mid - i1 + 1, p2,
                             mid + 1, i2);
    return root;
  }
};

class Solution2 {
public:
  /**
   * 去掉未使用的参数inorder和i2
   */
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> cache;
    for (int i = 0; i < inorder.size(); i++) {
      cache[inorder[i]] = i;
    }
    return buildTree_(cache, preorder, 0, preorder.size() - 1, 0);
  }

  TreeNode *buildTree_(unordered_map<int, int> &cache, vector<int> &preorder,
                       int p1, int p2, int i1) {
    if (p1 > p2) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[p1]);
    int mid = cache[preorder[p1]];
    root->left = buildTree_(cache, preorder, p1 + 1, p1 + mid - i1, i1);
    root->right = buildTree_(cache, preorder, p1 + mid - i1 + 1, p2, mid + 1);
    return root;
  }
};
