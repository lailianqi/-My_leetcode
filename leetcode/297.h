#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//自己写的代码
//下面是leetcode类似的答案
// https://discuss.leetcode.com/topic/31264/short-and-straight-forward-bfs-java-code-with-a-queue
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == NULL) {
            return "NULL";
        }
        queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        string res = "";
        while (!treeQueue.empty()) {
            TreeNode *current = treeQueue.front();
            treeQueue.pop();
            res = res + to_string(current->val) + " ";
            treeQueue.push(current->left);
            treeQueue.push(current->right);
            while (treeQueue.front() == NULL && !treeQueue.empty()) {
                res = res + "NULL ";
                treeQueue.pop();
            }
        }
        res = res.substr(0, res.size() - 1);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "NULL")
            return NULL;
        istringstream in(data);
        vector<string> res;
        queue<TreeNode *> treeQueue;
        for (string word; in >> word;) {
            res.push_back(word);
        }
        TreeNode *root = new TreeNode(stoi(res[0]));
        treeQueue.push(root);
        for (int i = 1; i < res.size(); i++) {
            TreeNode *parent = treeQueue.front();
            treeQueue.pop();
            if (res[i] != "NULL") {
                TreeNode *left = new TreeNode(stoi(res[i]));
                parent->left = left;
                treeQueue.push(left);
            }
            if (res[++i] != "NULL") {
                TreeNode *right = new TreeNode(stoi(res[i]));
                parent->right = right;
                treeQueue.push(right);
            }
        }
        return root;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/32470/clean-c-solution
class Solution_0 {
    class Codec {
      public:
        // Encodes a tree to a single string.
        string serialize(TreeNode *root) {
            if (root == NULL) {
                return "#";
            }
            return to_string(root->val) + "," + serialize(root->left) + "," +
                   serialize(root->right);
        }

        // Decodes your encoded data to tree.
        TreeNode *deserialize(string data) { return mydeserialize(data); }
        TreeNode *mydeserialize(string &data) {
            if (data[0] == '#') {
                if (data.size() > 1)
                    data = data.substr(2);
                return nullptr;
            } else {
                TreeNode *node = new TreeNode(helper(data));
                node->left = mydeserialize(data);
                node->right = mydeserialize(data);
                return node;
            }
        }

      private:
        int helper(string &data) {
            int pos = data.find(',');
            int val = stoi(data.substr(0, pos));
            data = data.substr(pos + 1);
            return val;
        }
    };
};
// leetcode的答案
// https://discuss.leetcode.com/topic/28041/recursive-preorder-python-and-c-o-n/2
class Solution_1 {
    class Codec {
      public:
        // Encodes a tree to a single string.
        string serialize(TreeNode *root) {
            ostringstream out;
            serialize(root, out);
            return out.str();
        }

        // Decodes your encoded data to tree.
        TreeNode *deserialize(string data) {
            istringstream in(data);
            return deserialize(in);
        }

      private:
        void serialize(TreeNode *root, ostringstream &out) {
            if (root) {
                out << root->val << " ";
                serialize(root->left, out);
                serialize(root->right, out);
            } else {
                out << "# ";
            }
        }
        TreeNode *deserialize(istringstream &in) {
            string word;
            in >> word;
            if (word == "#") {
                return NULL;
            }
            TreeNode *root = new TreeNode(stoi(word));
            root->left = deserialize(in);
            root->right = deserialize(in);
            return root;
        }
    };
};

void test() {
    Codec s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    cout << s.serialize(root);
}