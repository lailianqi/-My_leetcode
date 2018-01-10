#include <string>
#include <algorithm>
using namespace std;
//一次ac 但是运行效率一般
class Solution {
  public:
    string convertToBase7(int num) {
        string res;
        int temp = num < 0 ? -num : num;
        while (temp) {
            res = to_string(temp % 7) + res;
            temp = temp / 7;
        }
        return num == 0 ? "0" : num < 0 ? "-" + res : res;
    }
};

//上面的稍微的改进版
class Solution_0 {
  public:
    string convertToBase7(int num) {
        string res;
        int temp = num < 0 ? -num : num;
        while (temp) {
            res.push_back('0' + temp % 7);
            temp = temp / 7;
        }
        reverse(res.begin(), res.end());
        return num == 0 ? "0" : num < 0 ? "-" + res : res;
    }
};
//上面改为do_while
class Solution_1 {
  public:
    string convertToBase7(int num) {
        string res;
        int temp = num < 0 ? -num : num;
        do {
            res.push_back('0' + temp % 7);
            temp = temp / 7;
        } while (temp);
        reverse(res.begin(), res.end());
        return num < 0 ? "-" + res : res;
    }
};

// leetcode好像也是上面这种类型的答案