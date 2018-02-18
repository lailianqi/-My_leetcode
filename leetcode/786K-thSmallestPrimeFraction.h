#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 72周周赛
// 没写出来

// 来自LeetCode的答案 感觉是最清晰的解法
// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115486/Java-AC-O(max(nk)-*-logn)-Short-Easy-PriorityQueue
class Solution {
  public:
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
        typedef pair<int, int> PII;
        auto cmp = [&A](PII &a, PII &b) {
            return A[a.first] * A[b.second] > A[a.second] * A[b.first];
        };
        int m = A.size();
        priority_queue<PII, vector<PII>, decltype(cmp)> q(cmp);
        for (int i = 0; i < m - 1; ++i) {
            q.push(make_pair(i, m - 1));
        }
        PII temp;
        for (int i = 0; i < K; i++) {
            temp = q.top();
            q.pop();
            if (temp.second > temp.first + 1) {
                q.push(make_pair(temp.first, temp.second - 1));
            }
        }
        return {A[temp.first], A[temp.second]};
    }
};

//另外的一种写法 没有上面写的好
// class Solution {
class Solution_0 {
  public:
    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            long long x = a.first * b.second, y = b.first * a.second;
            return x < y;
        }
    };

    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
        sort(A.begin(), A.end());
        unordered_map<int, int> nxt;
        int n = A.size();
        for (int i = 0; i + 1 < n; ++i)
            nxt[A[i]] = A[i + 1];

        set<pair<int, int>, cmp> st; // i, j
        for (auto x : A)
            st.insert({1, x});
        for (int popped = 0; popped + 1 < K; ++popped) {
            auto &now = *st.begin();
            st.erase(st.begin());
            int first = now.first, j = now.second;
            if (nxt.find(first) != nxt.end() && nxt[first] < j) {
                st.insert({nxt[first], j});
            }
        }
        return vector<int>{st.begin()->first, st.begin()->second};
    }
};

//第三种解法  来自LeetCode 还没有完全理解
class Solution_1 {
  public:
    int count(vector<int> &A, int a, int b) {
        int num = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A.back() * a < A[i] * b)
                continue;
            int L = i + 1, R = (int)A.size() - 1;
            while (L < R) {
                int mid = (L + R) / 2;
                if (A[i] * b <= A[mid] * a)
                    R = mid;
                else
                    L = mid + 1;
            }
            num += A.size() - L;
        }
        return num;
    }
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
        int k1 = 0, k2 = 1;
        while (true) {
            int num = count(A, A[k1], A[k2]);
            if (num == K)
                return {A[k1], A[k2]};
            else if (num > K) {
                k2 += 1;
            } else {
                k1 += 1;
                if (k1 == k2)
                    k2 = k1 + 1;
            }
        }
        return {-1, -1};
    }
};