#include <vector>
#include <string>
using namespace std;
//You are here! Your runtime beats 55.63 % of cpp submissions.  3ms
class Solution {
  public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        k--;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            int index = k / factorial[n - i];
            num = num * 10 + numbers[index];
            numbers.erase(numbers.begin() + index);
            k = k - index * factorial[n - i];
        }
        return to_string(num);
    }
};