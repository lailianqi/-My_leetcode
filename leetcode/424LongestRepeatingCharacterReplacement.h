#include <string>
#include <vector>
using namespace std;
//滑动窗口的解法 一开始根本没有想到 直接看的leetcode的答案
// https://discuss.leetcode.com/topic/63494/java-12-lines-o-n-sliding-window-solution-with-explanation
// https://www.cnblogs.com/reboot329/p/5968393.html
class Solution {
  public:
    int characterReplacement(string s, int k) {
        int maxCharNum = 0, res = 0, start = 0;
        vector<int> dir(26, 0);
        for (int i = 0; i < s.size(); i++) {
            maxCharNum = max(maxCharNum, ++dir[s[i] - 'A']);
            while (i - start + 1 - maxCharNum > k) {
                dir[s[start] - 'A']--;
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};
//下面是上面解法的改进版 来自leetcode
// https://discuss.leetcode.com/topic/63494/java-12-lines-o-n-sliding-window-solution-with-explanation/2
// https://discuss.leetcode.com/topic/63416/sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters/9
// sp大神的解法 和这个差不多 https://discuss.leetcode.com/topic/63456/7-lines-c
class Solution_0 {
  public:
    int characterReplacement(string s, int k) {
        int maxCharNum = 0, res = 0, start = 0;
        vector<int> dir(26, 0);
        for (int i = 0; i < s.size(); i++) {
            maxCharNum = max(maxCharNum, ++dir[s[i] - 'A']);
            while (maxCharNum + k < i - start + 1) {
                dir[s[start] - 'A']--;
                start++;
            }
        }
        return s.size() - start;
    }
};