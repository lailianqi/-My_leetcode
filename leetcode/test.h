#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    bool isValid(string s) {
        stack<char> sta;
        map<char, char> bracketsMap;
        bracketsMap[')'] = '(';
        bracketsMap['}'] = '{';
        bracketsMap[']'] = '[';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (!sta.empty() && sta.top() == bracketsMap[s[i]]) {
                    sta.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                sta.push(s[i]);
            }
        }
        return sta.empty();
    }
};
void test() {
    Solution sw;
    string s = "(1+2)/(0.5+1))";
    if (sw.isValid(s))
        cout << "yes" << endl;
    else {
        cout << "NO" << endl;
    }
}

TreeNode *maxTreeNode(TreeNode *root) {
    TreeNode *pMax, *curr = root;
    if (root == NULL) {
        return NULL;
    }
    if (root->left) {
        pMax = maxTreeNode(root->left);
        if (curr->val < pMax->val) {
            curr = pMax;
        }
    }
    if (root->right) {
        pMax = maxTreeNode(root->right);
        if (curr->val < pMax->val) {
            curr = pMax;
        }
    }
    return curr;
}
void trave() {}

int foo2(int data[n], int rand) {
    int sum = 0;
    long begin = rdtsc();
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < n; j++) {
            if (data[j] >= rand) {
                sum += data[j];
            }
        }
    }
    printf("%ld\n", rdtsc() - begin);
    return sum;
}