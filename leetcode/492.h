#include <vector>
#include <cmath>
using namespace std;
//一次ac  但是是用的暴力的解法 因为测试的例子太少 所以时间效率还行
class Solution {
  public:
    vector<int> constructRectangle(int area) {
        int minValue = INT_MAX;
        vector<int> res(2, 0);
        for (int w = 1; w * w <= area; w++) {
            if (area % w == 0) {
                int L = area / w;
                if (minValue > (L + w)) {
                    minValue = (L + w);
                    res[0] = L, res[1] = w;
                }
            }
        }
        return res;
    }
};

//数学方法的解法 来自于leetcode的解法 解法的依据是L和W尽可能的靠近
// https://discuss.leetcode.com/topic/77526/3-line-c-clean-solution-with-explanation
// https://discuss.leetcode.com/topic/76314/3-line-clean-and-easy-understand-solution
class Solution_0 {
  public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w != 0) {
            w--;
        }
        return vector<int>{area / w, w};
    }
};