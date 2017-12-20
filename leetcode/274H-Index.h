#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//最原始的答案 直接看图写出来的 时间的复杂度为 nlog(n)
class Solution {
  public:
    int hIndex(vector<int> &citations) {
        int m = citations.size();
        sort(citations.begin(), citations.end(),
             [](int x, int y) { return x > y; });
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (citations[i] >= i + 1) {
                res++;
            }
        }
        return res;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/25560/simple-java-solution-with-sort
//先将数组排序，我们就可以知道对于某个引用数，有多少文献的引用数大于这个数。
class Solution_0 {
  public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= len) {
                return len;
            } else {
                len--;
            }
        }
        return len;
    }
};

//上面方法的改进版
// https://discuss.leetcode.com/topic/23358/a-clean-o-n-solution-in-java
class Solution_1 {
  public:
    int hIndex(vector<int> &citations) {
        int m = citations.size();
        vector<int> counter(m + 1, 0);
        for (auto element : citations) {
            if (element > m)
                counter[m]++;
            else
                counter[element]++;
        }
        int total = 0;
        for (int i = m; i >= 0; i--) {
            total += counter[i];
            if (total >= i)
                return i;
        }
        return 0;
    }
};

void test() {
    Solution s;
    vector<int> citation = {3, 0, 6, 1, 5};
    cout << s.hIndex(citation) << endl;
}