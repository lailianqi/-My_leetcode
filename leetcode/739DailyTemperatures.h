#include <vector>
#include <stack>
using namespace std;
//自己的第一种方案 成功ac
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> temperaturesStack;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!temperaturesStack.empty() &&
                   temperatures[i] > temperatures[temperaturesStack.top()]) {
                int index = temperaturesStack.top();
                temperaturesStack.pop();
                res[index] = i - index;
            }
            temperaturesStack.push(i);
        }
        return res;
    }
};
void test() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    s.dailyTemperatures(temperatures);
}