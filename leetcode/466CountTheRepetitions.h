#include <string>
#include <vector>
using namespace std;
//暴力破解的解法  肯定是过不去ac的
class Solution {
  public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int counter1 = 0, counter2 = 0, i = 0, j = 0;
        while (counter1 < n1) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == s2.size()) {
                    j = 0;
                    counter2++;
                }
            }
            i++;
            if (i == s1.size()) {
                i = 0;
                counter1++;
            }
        }
        return counter2 / n2;
    }
};
// leetcode 的解法
// https://discuss.leetcode.com/topic/72105/c-solution-inspired-by-70664914-with-organized-explanation/2
class Solution_0 {
  public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(s2.size() + 1, 0);
        vector<int> nextIndex(s2.size() + 1, 0);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == s2.size()) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            repeatCount[k] = cnt;
            nextIndex[k] = j;
            for (int start = 0; start < k; start++) {
                if (nextIndex[start] == j) {
                    int prefixCount = repeatCount[start];
                    int patternCount = (repeatCount[k] - repeatCount[start]) *
                                       ((n1 - start) / (k - start));
                    int suffixCount =
                        repeatCount[start + (n1 - start) % (k - start)] -
                        repeatCount[start];
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return repeatCount[n1] / n2;
    }
};