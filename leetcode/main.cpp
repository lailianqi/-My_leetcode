// #include "test4.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// #include "809.h"
using namespace std;

void test() {
    long m, n;
    cin >> m >> n;
    vector<long> num(n, 0);
    for (long i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    if (num[0] != 1) {
        cout << -1 << endl;
    }
    long sum = 0, ans = 0;
    while (sum < m) {
        for (long i = n - 1; i >= 0; i--)
            if (sum + 1 >= num[i]) {
                sum += num[i], ans++;
                break;
            }
    }
    cout << ans << endl;
}
long main() {
    // test();
    test();
    return 0;
}

