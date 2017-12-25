#include <string>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//直接参照297题目的写法 成功ac 但是感觉效率一般
// leetcode上相同思路的答案
// https://discuss.leetcode.com/topic/66651/java-preorder-queue-solution/27?page=2
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

//另外的一种方法用的队列 并且用到了二叉搜索树的性质 来自leetcode的答案 效率很高
// https://discuss.leetcode.com/topic/66651/java-preorder-queue-solution
class Codec_0 {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string order;
        preOrder(root, order);
        return order;
    }
    void preOrder(TreeNode *root, string &s) {
        if (root) {
            char buf[4];
            memcpy(buf, &(root->val), sizeof(int)); // burn the int into 4 chars
            for (int i = 0; i < 4; i++)
                s.push_back(buf[i]);
            preOrder(root->left, s);
            preOrder(root->right, s);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int pos = 0;
        return mydeserialize(data, pos, INT_MIN, INT_MAX);
    }
    TreeNode *mydeserialize(const string &buffer, int &pos, int minValue,
                            int maxValue) {
        if (pos >= buffer.size())
            return NULL; // using pos to check whether buffer ends is better
                         // than using char* directly.
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue)
            return NULL;
        TreeNode *node = new TreeNode(value);
        pos += sizeof(int);
        node->left = mydeserialize(buffer, pos, minValue, value);
        node->right = mydeserialize(buffer, pos, value, maxValue);
        return node;
    }
};