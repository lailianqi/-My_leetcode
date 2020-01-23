#include <bits/stdc++.h>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
  public:
    map<int, RandomListNode *> directory;
    RandomListNode *copyRandomList(RandomListNode *head) { return clone(head); }
    RandomListNode *clone(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        if (directory.find(head->label) != directory.end()) {
            return directory[head->label];
        }
        RandomListNode *root = new RandomListNode(head->label);
        directory[root->label] = root;
        root->next = clone(head->next);
        root->random = clone(head->random);
        return root;
    }
};

// 二刷时候的解法
class Solution_1 {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> dir;
        RandomListNode *current = head;
        while (current) {
            dir[current] = new RandomListNode(current->label);
            current = current->next;
        }
        current = head;
        while (current) {
            dir[current]->next = current->next ? dir[current->next] : NULL;
            dir[current]->random =
                current->random ? dir[current->random] : NULL;
            current = current->next;
        }
        return dir[head];
    }
};

class Solution_2 {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) { return clone(head); }
    RandomListNode *clone(RandomListNode *head) {
        if (head == NULL) {
            return head;
        }
        if (dir.count(head)) {
            return dir[head];
        }
        RandomListNode *root = new RandomListNode(head->label);
        dir[head] = root;
        root->next = clone(head->next);
        root->random = clone(head->random);
        return root;
    }

  private:
    unordered_map<RandomListNode *, RandomListNode *> dir;
};