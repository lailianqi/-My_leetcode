#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac
class Solution {
  public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        auto it =
            min_element(letters.begin(), letters.end(), [&](char a, char b) {
                if (a == target) {
                    return false;
                }
                int distanceA = (a - target + 26) % 26;
                distanceA = distanceA == 0 ? 26 : distanceA;
                int distanceB = (b - target + 26) % 26;
                distanceB = distanceB == 0 ? 26 : distanceB;
                return distanceA < distanceB;
            });
        return *it;
    }
};

// leetcode 的解法 直接用的二分查找
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/110005/Easy-Binary-Search-in-Java-O(log(n))-time
class Solution_0 {
  public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int n = letters.size(), lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return letters[lo % n];
    }
};

// 自己对上面的改进版 直接用的stl库 leetcode也有相同的解法
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/112825/C++-2-lines-Solution-using-upper_bound
class Solution_1 {
  public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? *letters.begin() : *it;
    }
};

// python的解法 来自LeetCode
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/110030/Python-no-brainer!