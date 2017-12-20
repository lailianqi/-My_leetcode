#include <vector>
using namespace std;
//自己的答案
class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int sum = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += sum;
            sum = digits[i] / 10;
            digits[i] %= 10;
        }
        if (sum > 0) {
            digits.insert(digits.begin(), sum);
        }
        return digits;
    }
};

//leetcode上比较好的答案
class Solution_0 {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        
        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
};