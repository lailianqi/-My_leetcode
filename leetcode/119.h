#include <vector>
using namespace std;

//里面包含动态规划最重要的空间的优化的思想，自己写的，未参考任何的代码
class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1, 1);
        int pre = 1;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++) {
                int temp = answer[j];
                answer[j] = answer[j] + pre;
                pre = temp;
            }
        }
        return answer;
    }
};
// leetCode另一种写法
class Solution_0 {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1, 0);
        answer[0] = 1;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                answer[j] = answer[j] + answer[j - 1];
            }
        }
        return answer;
    }
};