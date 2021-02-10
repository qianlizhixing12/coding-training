#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  TreeNode *dfs(vector<int> &pre, unordered_map<int, int> &c1, int s1, int e1,
                vector<int> &post, unordered_map<int, int> &c2, int s2,
                int e2) {
    if (s1 > e1) {
      return NULL;
    } else if (s1 == e1) {
      return new TreeNode(pre[s1]);
    }
    TreeNode *root = new TreeNode(pre[s1]);
    s1++;
    e2--;
    int mid1 = c1[post[e2]];
    int mid2 = c2[pre[s1]];
    root->left = dfs(pre, c1, s1, mid1 - 1, post, c2, s2, mid2);
    root->right = dfs(pre, c1, mid1, e1, post, c2, mid2 + 1, e2);
    return root;
  }

public:
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    unordered_map<int, int> c1;
    unordered_map<int, int> c2;
    for (int i = 0; i < pre.size(); i++) {
      c1[pre[i]] = i;
    }
    for (int i = 0; i < post.size(); i++) {
      c2[post[i]] = i;
    }
    return dfs(pre, c1, 0, pre.size() - 1, post, c2, 0, post.size() - 1);
  }
};

int main() {
  vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
  vector<int> post = {4, 5, 2, 6, 7, 3, 1};
  Solution().constructFromPrePost(pre, post);
  return 0;
}