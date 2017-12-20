#include <vector>
using namespace std;

//参考leetcoded的写法
/*
My idea is to generate the sequence iteratively. For example, when n=3, we can
get the result based on n=2.
00,01,11,10 -> (000,001,011,010 ) (110,111,101,100). The middle two numbers only
differ at their highest bit, while the rest numbers of part two are exactly
symmetric of part one. It is easy to see its correctness.
*/
class Solution {
  public:
    vector<int> grayCode(int n) {
        vector<int> answer;
        answer.push_back(0);
        for (int i = 0; i < n; i++) {
            int size = answer.size();
            for (int j = size - 1; j >= 0; j--) {
                answer.push_back(answer[j] | 1 << i);
            }
        }
        return answer;
    }
};

//用公式
// The idea is simple. G(i) = i^ (i/2).
class Solution_0 {
  public:
    vector<int> grayCode(int n) {
        vector<int> answer;
        for (int i = 0; i < 1 << n; i++) {
            answer.push_back(i ^ i >> 1);
        }
        return answer;
    }
};