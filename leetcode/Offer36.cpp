#include <cstdlib>

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

class Solution {
private:
  Node *cur;
  void dfs(Node *root) {
    if (root == NULL) {
      return;
    }
    dfs(root->left);
    cur->right = root;
    root->left = cur;
    cur = root;
    dfs(root->right);
  }

public:
  Node *treeToDoublyList(Node *root) {
    if (root == NULL) {
      return root;
    }
    Node head(0);
    cur = &head;
    dfs(root);
    cur->right = head.right;
    head.right->left = cur;
    return head.right;
  }
};