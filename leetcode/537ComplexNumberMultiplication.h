#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
//自己的第一种方法 成功ac 但是感觉写的太乱了
class Solution {
  public:
    string complexNumberMultiply(string a, string b) {
        map<string, int> dir;
        string a1, b1;
        string a2, b2;
        split(a, a1, b1);
        split(b, a2, b2);
        dir["constant"] = stoi(a1) * stoi(a2);
        dir["i"] = stoi(a1) * stoi(b2) + stoi(b1) * stoi(a2);
        dir["i^2"] = stoi(b1) * stoi(b2);
        string result;
        return result + to_string(dir["constant"] - dir["i^2"]) + "+" +
               to_string(dir["i"]) + "i";
    }
    void split(string &s, string &a, string &b) {
        int index = s.find_first_of('+');
        int index2 = s.find_last_of('i');
        a = s.substr(0, index);
        b = s.substr(index + 1, index2 - index - 1);
    }
};

// leetcode的写法 牛逼多了 比自己的写法好太多了
// https://discuss.leetcode.com/topic/84382/c-using-stringstream
class Solution_0 {
  public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra * rb - ia * ib << "+" << ra * ib + rb * ia << "i";
        return ans.str();
    }
};

//牛逼的python的写法 来自leetcode
// https://discuss.leetcode.com/topic/84287/python-simple-3-lines-solution

//牛逼的java的写法 来自leetcode
// https://discuss.leetcode.com/topic/84261/java-3-liner