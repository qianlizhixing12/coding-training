#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> reversePrint(ListNode *head) {
    vector<int> rst;
    while (head != NULL) {
      rst.emplace_back(head->val);
      head = head->next;
    }
    reverse(rst.begin(), rst.end());
    return rst;
  }
};