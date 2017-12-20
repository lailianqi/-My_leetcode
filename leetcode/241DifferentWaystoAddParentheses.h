#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//一开始没有想出来
// leetcode的答案
// https://discuss.leetcode.com/topic/19901/a-recursive-java-solution-284-ms/3
// https://discuss.leetcode.com/topic/19906/c-4ms-recursive-dp-solution-with-brief-explanation
class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> outputs;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                string left = input.substr(0, i);
                string right = input.substr(i + 1);
                vector<int> lval = diffWaysToCompute(left);
                vector<int> rval = diffWaysToCompute(right);
                for (auto l : lval) {
                    for (auto r : rval) {
                        switch (input[i]) {
                        case '+':
                            outputs.push_back(l + r);
                            break;
                        case '-':
                            outputs.push_back(l - r);
                            break;
                        default:
                            outputs.push_back(l * r);
                        }
                    }
                }
            }
        }
        if (outputs.empty()) {
            outputs.push_back(stoi(input));
        }
        return outputs;
    }
};

//下面是上面的简写 也是leetcode的答案
// https://discuss.leetcode.com/topic/19894/1-11-lines-python-9-lines-c/2
class Solution_0 {
  public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (ispunct(c))
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i + 1)))
                        output.push_back(c == '+' ? a + b : c == '-' ? a - b
                                                                     : a * b);
        }
        return output.size() ? output : vector<int>{stoi(input)};
    }
};