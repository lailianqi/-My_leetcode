#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> a(n, 0);
        Backtrack(a, 0, sum);
        return sum;
    }
    void Backtrack(vector<int> &a, int deep, int &sum) {
        int n = a.size();
        if (deep >= n) {
            sum++;
        } else {
            for (int j = 0; j < n; j++) {
                a[deep] = j;
                if (Isvalid(a, deep)) {
                    Backtrack(a, deep + 1, sum);
                }
            }
        }
    }
    // check the validity of each position
    bool Isvalid(vector<int> &a, int k) {
        for (int i = 0; i < k; i++) {
            if (abs(k - i) == abs(a[i] - a[k]) || a[i] == a[k])
                return false;
        }
        return true;
    }
};