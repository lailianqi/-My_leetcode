#include <string>
#include <unordered_map>
using namespace std;
// 其实我的第一个想法是和下面的答案的想法差不多 知道是sliding windows的写法
// 但是我没写出来 下面是这种题最标准的写法
// https://discuss.leetcode.com/topic/87868/java-solution-two-pointers
class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int m = s1.length(), n = s2.length();
        unordered_map<char, int> dir;
        for (int i = 0; i < s1.size(); i++) {
            dir[s1[i]]++;
        }
        int i = 0, j = 0, cnt = m;
        while (j < n) {
            if (dir[s2[j++]]-- > 0) {
                cnt--;
            }
            while (cnt == 0) {
                if (j - i == m) {
                    return true;
                }
                if (dir[s2[i++]]++ == 0) {
                    cnt++;
                }
            }
        }
        return false;
    }
};

// 另外的一种解法  比较简单 但是不通用 sliding windows的解法 比上面的解法简单
// https://discuss.leetcode.com/topic/87845/java-solution-sliding-window
class Solution_0 {
  public:
    bool checkInclusion(string s1, string s2) {
        vector<int> dir(26, 0);
        if (s1.length() > s2.length()) {
            return false;
        }
        int m = s1.length(), n = s2.length();
        for (int i = 0; i < m; i++) {
            dir[s1[i] - 'a']++;
            dir[s2[i] - 'a']--;
        }
        if (allZero(dir))
            return true;
        for (int i = m; i < n; i++) {
            dir[s2[i] - 'a']--;
            dir[s2[i - m] - 'a']++;
            if (allZero(dir))
                return true;
        }
        return false;
    }
    bool allZero(vector<int> &dir) {
        for (int i = 0; i < 26; i++) {
            if (dir[i] != 0)
                return false;
        }
        return true;
    }
};

// 第三种解法 来自LeetCode
// https://discuss.leetcode.com/topic/87915/oneliners-in-python-and-c/2
// https://discuss.leetcode.com/topic/87884/8-lines-slide-window-solution-in-java
/*
public boolean checkInclusion(String s1, String s2) {
    int [] map = new int [256];
    for (char ch : s1.toCharArray()) map [ch] ++;
    for (int idx = 0, start = 0; idx < s2.length(); idx ++) {
        char ch = s2.charAt (idx);
        if (-- map [ch] < 0) while (map [ch] != 0) map [s2.charAt (start ++)] ++;
         else if (idx - start + 1 == s1.length()) return true;
    }
    return false;
}
*/