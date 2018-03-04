#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isInVaildBoardary(vector<vector<int>> &grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    if (row >= 0 && row < m && col >= 0 && col < n) {
        return true;
    }
    return false;
}

struct Comparator {
    bool operator()(const std::pair<int, int> &lhs,
                    const std::pair<int, int> &rhs) const {
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        else
            return lhs.first < rhs.first;
    }
};

class Employee {
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
int helper(unordered_map<int, Employee *> &dir, int id) {
    return dir[id]->importance +
           accumulate(dir[id]->subordinates.begin(),
                      dir[id]->subordinates.end(), 0,
                      [&](int sum, int id) { return sum + helper(dir, id); });
}

int getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, Employee *> dir;
    transform(
        employees.begin(), employees.end(), inserter(dir, dir.end()),
        [&](Employee *element) { return make_pair(element->id, element); });
    return helper(dir, id);
}

int minimumDeleteSum(string A, string B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = A[i - 1] == B[j - 1] ? (dp[i - 1][j - 1] + 1)
                                            : (max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[m][n];
}

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    for (; i < s.size() && j < t.size(); j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }
    return i == s.size();
}