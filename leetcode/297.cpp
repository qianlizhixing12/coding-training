#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
  void dfs(TreeNode *root, string &ans) {
    if (root == NULL) {
      ans += "null,";
      return;
    }
    ans += to_string(root->val) + ",";
    dfs(root->left, ans);
    dfs(root->right, ans);
  }

  void SplitString(const std::string &s, std::vector<std::string> &v,
                   const std::string &c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
      v.push_back(s.substr(pos1, pos2 - pos1));

      pos1 = pos2 + c.size();
      pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
      v.push_back(s.substr(pos1));
  }

  TreeNode *dfs(vector<string> &cache, int &pos) {
    if (pos >= cache.size() || cache[pos] == "null") {
      pos++;
      return NULL;
    }
    TreeNode *root = new TreeNode(atoi(cache[pos].c_str()));
    pos++;
    root->left = dfs(cache, pos);
    root->right = dfs(cache, pos);
    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans;
    dfs(root, ans);
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<string> cache;
    SplitString(data, cache, ",");
    int pos = 0;
    return dfs(cache, pos);
  }
};