#include <algorithm>
#include <vector>
using namespace std;
// 这题想歪了 所以第一次在LeetCode并没有写出来 其实并不难
// 来自LeetCode的答案
// https://leetcode.com/problems/shopping-offers/discuss/105194/Simple-Java-recursive-solution?page=2
class Solution {
  public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &needs) {
        return helper(price, special, needs);
    }

    int helper(vector<int> &price, vector<vector<int>> &special,
               vector<int> &needs) {
        int res = INT_MAX;
        for (int i = 0; i < special.size(); i++) {
            if (isValid(special[i], needs)) {
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] -= special[i][j];
                }
                res =
                    min(res, special[i].back() + helper(price, special, needs));
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] += special[i][j];
                }
            }
        }
        int norSum = 0;
        for (int i = 0; i < needs.size(); i++) {
            norSum += needs[i] * price[i];
        }
        return res = min(res, norSum);
    }
    bool isValid(vector<int> &special, vector<int> &needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (special[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }
};

// 还可以在这个解法上增加备忘录的解法 这里就不写了