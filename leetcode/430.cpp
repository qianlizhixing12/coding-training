#include <stdlib.h>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {

public:
  Node *flatten(Node *head) {
    if (head == NULL) {
      return head;
    }
    // 哨兵
    Node sentry;
    sentry.prev = sentry.next = sentry.child = NULL;
    Node *cur = &sentry;
    stack<Node *> help;
    help.push(head);

    while (!help.empty()) {
      Node *temp = help.top();
      help.pop();
      cur->next = temp;
      temp->prev = cur;
      cur = cur->next;
      if (cur->next != NULL) {
        help.push(cur->next);
        cur->next = NULL;
      }
      if (cur->child != NULL) {
        help.push(cur->child);
        cur->child = NULL;
      }
    }
    sentry.next->prev = NULL;

    return sentry.next;
  }

  Node *flatten_(Node *head) {
    if (head == NULL) {
      return head;
    }
    // 哨兵
    Node sentry;
    sentry.prev = sentry.next = sentry.child = NULL;
    Node *cur = &sentry;
    flatten_dfs(cur, head);
    sentry.next->prev = NULL;
    return sentry.next;
  }

  Node *flatten_dfs(Node *prev, Node *cur) {
    if (cur == NULL) {
      return prev;
    }
    prev->next = cur;
    cur->prev = prev;
    prev = cur;
    Node *next = cur->next;
    Node *child = flatten_dfs(cur, cur->child);
    cur->child = NULL;
    return flatten_dfs(child, next);
  }
};