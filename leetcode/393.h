#include <vector>
using namespace std;
//题目的意思非常的难懂 题目本身不难 下面是题目翻译的网址
// https://segmentfault.com/a/1190000008228590
// https://discuss.leetcode.com/topic/57195/concise-c-implementation
class Solution {
  public:
    bool validUtf8(vector<int> &data) {
        int counter = 0;
        for (int i = 0; i < data.size(); i++) {
            if (counter == 0) {
                if ((data[i] >> 5) == 0b110) {
                    counter = 1;
                } else if ((data[i] >> 4) == 0b1110) {
                    counter = 2;
                } else if ((data[i] >> 3) == 0b11110) {
                    counter = 3;
                } else if ((data[i] >> 7) == 0b1) {
                    return false;
                }
            } else {
                if ((data[i] >> 6) != 0b10)
                    return false;
                counter--;
            }
        }
        return counter == 0 ? true : false;
    }
};