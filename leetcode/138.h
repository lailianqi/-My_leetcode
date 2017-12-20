#include <string>
#include <map>
#include <queue>
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