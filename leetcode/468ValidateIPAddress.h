#include <sstream>
#include <string>
using namespace std;
//一看就不会写的题目
// leetcode的答案
// https://discuss.leetcode.com/topic/71439/c-solution-straightforward-string-processing

class Solution {
  public:
    string validIPAddress(string IP) {
        string ans[3] = {"IPv4", "IPv6", "Neither"}, block;
        stringstream ss(IP);
        // ipv4 candidate
        if (IP.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; i++) {
                if (!getline(ss, block, '.') || !isValidIPv4Block(block))
                    return ans[2];
            }
            return ss.eof() ? ans[0] : ans[2];
        }
        // ipv6 candidate
        else if (IP.substr(0, 5).find(':') != string::npos) {
            for (int i = 0; i < 8; i++) {
                if (!getline(ss, block, ':') || !isValidIPv6Block(block))
                    return ans[2];
            }
            return ss.eof() ? ans[1] : ans[2];
        }
        return ans[2];
    }
    bool isValidIPv4Block(string &block) {
        int num = 0;
        if (block.size() > 0 && block.size() <= 3) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1)) {
                    return false;
                } else {
                    num *= 10;
                    num += c - '0';
                }
            }
            return num <= 255;
        }
        return false;
    }
    bool isValidIPv6Block(string &block) {
        if (block.size() > 0 && block.size() <= 4) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                if (validIPv6Chars.find(c) == string::npos)
                    return false;
            }
            return true;
        }
        return false;
    }

  private:
    const string validIPv6Chars = "0123456789abcdefABCDEF";
};

// leetcode 上更加牛逼的解法 正则表达式
// https://discuss.leetcode.com/topic/71418/short-regexp-solution