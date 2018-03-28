#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int test();
int test() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> value(n, 0), dp(capacity + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = capacity; j >= 0; j--) {
            if (j - value[i] >= 0) {
                dp[j] = max(dp[j], dp[j - value[i]] + 1);
            }
        }
    }
    cout << dp[capacity] << endl;
    return 0;
}

int helper(vector<int> &value, int start, int cur, int capacity) {
    if (start >= value.size()) {
        return 1;
    }
    int res = 0;
    if (cur + value[start] <= capacity) {
        res += helper(value, start + 1, cur + value[start], capacity);
    }
    res += helper(value, start + 1, cur, capacity);
    return res;
}

int test1() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cout << helper(value, 0, 0, capacity) << endl;
    return 0;
}