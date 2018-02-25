#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 73周周赛 未参加
// 自己的第一种方案 成功ac
class Solution {
  public:
    string customSortString(string S, string T) {
        sort(T.begin(), T.end(),
             [&](char a, char b) { return S.find(a) < S.find(b); });
        return T;
    }
};



// 下面两个链接是LeetCode上面还不错的写法

// https://leetcode.com/problems/custom-sort-string/discuss/116548/2-lines-Python
// def customSortString(self, S, T):
//         c, s = collections.Counter(T), set(S)
//         return ''.join(i * c[i] for i in S) + ''.join(i * c[i] for i in c if i not in s)


// https://leetcode.com/problems/custom-sort-string/discuss/116555/JAVA-4ms-solution
// public String customSortString(String S, String T) {
//        int[] count = new int[128];
//        for(char ch : T.toCharArray())
//            count[ch]++;
//        StringBuilder sb = new StringBuilder();
//        for(char ch : S.toCharArray())
//            while(count[ch]-- > 0)
//                sb.append(ch);
//        for(int i = 0; i < 128; i++)
//            while(count[i]-- > 0)
//                sb.append((char)i);
//        return sb.toString();
//    }