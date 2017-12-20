#include <string>
#include <vector>
using namespace std;
// 一开始并没有想到解法   下面是leetcode答案的改写版
// https://discuss.leetcode.com/topic/57735/c-recursive-solution
//与这个解法差不多
// https://discuss.leetcode.com/topic/57372/java-divide-and-conquer-recursion-solution?page=1
//下面链接的解法一般
// https://discuss.leetcode.com/topic/57372/java-divide-and-conquer-recursion-solution?page=1
class Solution {
  public:
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size() - 1);
    }
    int helper(string &s, int k, int start, int end) {
        if (end - start + 1 < k)
            return 0;
        vector<int> dir(26, 0);
        for (int i = start; i <= end; i++) {
            dir[s[i] - 'a']++;
        }
        int index = start;
        while (index <= end && dir[s[index] - 'a'] >= k) {
            index++;
        }
        if (index > end) {
            return (end - start + 1);
        }
        return max(helper(s, k, start, index - 1),
                   helper(s, k, index + 1, end));
    }
};
//上面自己的改进版
//但是速度并没有提升多少
class Solution_0 {
  public:
    int longestSubstring(string s, int k) {
        vector<int> dir(26, 0);
        return helper(s, k, 0, s.size() - 1, dir);
    }
    int helper(string &s, int k, int start, int end, vector<int> &dir) {
        if (end - start + 1 < k)
            return 0;
        setZero(dir);
        for (int i = start; i <= end; i++) {
            dir[s[i] - 'a']++;
        }
        int index = start;
        while (index <= end && dir[s[index] - 'a'] >= k) {
            index++;
        }
        if (index > end) {
            return (end - start + 1);
        }
        return max(helper(s, k, start, index - 1, dir),
                   helper(s, k, index + 1, end, dir));
    }
    void setZero(vector<int> &dir) {
        for (auto &element : dir) {
            element = 0;
        }
    }
};