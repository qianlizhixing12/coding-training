#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (NULL == root) {
      return null_;
    }

    return to_string(root->val) + sep_ + serialize(root->left) + sep_ +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<string> s;
    splitString(data, sep_, s);
    int pos = 0;
    return dfs(s, pos);
  }

private:
  string sep_ = ",";
  string null_ = "null";

  void splitString(const string &s, const string &sep, vector<string> &result) {
    string::size_type pos1 = 0;
    string::size_type pos2 = string::npos;
    while (true) {
      pos2 = s.find(sep, pos1);
      if (string::npos == pos2) {
        break;
      }
      result.emplace_back(s.substr(pos1, pos2 - pos1));
      pos1 = pos2 + sep.size();
    }
    if (pos1 != s.size()) {
      result.push_back(s.substr(pos1));
    }
  }

  TreeNode *dfs(const vector<string> &s, int &pos) {
    if (pos >= s.size() || null_ == s[pos]) {
      pos++;
      return NULL;
    }

    TreeNode *result = new TreeNode(atoi(s[pos].c_str()));
    pos++;
    result->left = dfs(s, pos);
    result->right = dfs(s, pos);
    return result;
  }
};
