#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    queue<Node *> help;
    help.push(root);
    while (!help.empty()) {
      int size = help.size();
      vector<int> level(size);
      for (int i = 0; i < size; i++) {
        Node *temp = help.front();
        help.pop();
        level[i] = temp->val;
        for (Node *it : temp->children) {
          help.push(it);
        }
      }
      result.push_back(level);
    }
    return result;
  }
};