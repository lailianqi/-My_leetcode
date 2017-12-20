#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
//下面是错误的做法,set会超时
class Solution {
  public:
    int countPrimes(int n) {
        int res = 0;
        set<int> directory;
        for (int i = 2; i < n; i++) {
            if (!directory.count(i)) {
                res++;
                for (int j = 2; i * j < n; j++) {
                    directory.insert(i * j);
                }
            }
        }
        return res;
    }
};
//下面的做法会超时
class Solution_0 {
  public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i))
                res++;
        }
        return res;
    }
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

//下面是leetcode的做法,不用Set
// https://discuss.leetcode.com/topic/13654/my-simple-java-solution
class Solution_1 {
  public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> notPrime(n, false);
        for (int i = 2; i < n; i++) {
            if (!notPrime[i]) {
                res++;
                for (int j = 2; i * j < n; j++) {
                    notPrime[i * j] = true;
                }
            }
        }
        return res;
    }
};

// Short C++ Sieve of Eratosthenes solution
// leetcode的解法
// https://discuss.leetcode.com/topic/17034/short-c-sieve-of-eratosthenes-solution
//下面是答案的改版，和原始的答案有点去区别
class Solution_2 {
  public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i; i * j < n; j++) {
                    prime[i * j] = false;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};
void test() {
    Solution s;
    s.countPrimes(11);
}