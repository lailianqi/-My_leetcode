#include <vector>
#include <iostream>
#include <string>
using namespace std;
//自己的答案
class Solution {
  public:
    vector<vector<int>> answers;
    vector<vector<int>> combine(int n, int k) {
        // vector<vector<int>> answers;
        vector<int> answer;
        combinePart(answer, 1, n, k);
        return answers;
    }

    void combinePart(vector<int> &answer, int deep, int n, int k) {
        if (answer.size() >= k) {
            answers.push_back(answer);
            return;
        }
        for (int i = deep; i <= n; i++) {
            answer.push_back(i);
            combinePart(answer, i + 1, n, k);
            answer.pop_back();
        }
    }
};

class Solution_1 {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> result(n, 0);
        int i;
        while (i >= 0) {
            result[i]++;
            if (result[i] > n) {
                i--;
            } else if (i == k - 1) {
                results.push_back(result);
            } else {
                i++;
                result[i] = result[i - 1];
            }
        }
        return results;
    }
};

class Solution_2 {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n)
                --i;
            else if (i == k - 1)
                result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};

// https://discuss.leetcode.com/topic/26689/short-iterative-c-answer-8ms/11
//迭代回溯

class Solution_0 {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> c(k, 0); // vector of length k, all 0s
        int i = 0;
        while (i >= 0) {
            // Increment element at index i
            c[i]++;
            cout << "Incremented element at index " << i << endl;
            cout << toString(c) << endl;

            /* Move index to the left if the element
             * at index i has exceeded n.
             */
            if (c[i] > n) {
                i--;
                cout << "n exceeded at " << i + 1
                     << ", moving index to the left" << endl;
            }

            /* If the index is at the end of the vector
             * c, then (because the other conditions are
             * obeyed), we know we have a valid combination,
             * so push it to our ans vector<vector<>>
             */
            else if (i == k - 1) {
                ans.push_back(c);
                cout << "Combination found!" << endl;
                cout << "Added " << toString(c) << " as an answer!" << endl;
            }

            /* Move index to the right and set the
             * element at that index equal to the
             * element at the previous index.
             *
             * Because of the increment at the beginning
             * of this while loop, we ensure that the
             * element at this index will be at least
             * one more than its neighbor to the left.
             */
            else {
                i++;
                c[i] = c[i - 1];
                cout << "Moved index to the right, and copied the value"
                     << " from the left" << endl;
                cout << toString(c) << endl;
            }
        }
        return ans;
    }
};

/*
Incremented element at index 0
[1, 0]
Moved index to the right, and copied the value from the left
[1, 1]
Incremented element at index 1
[1, 2]
Combination found!
Added [1, 2] as an answer!
Incremented element at index 1
[1, 3]
Combination found!
Added [1, 3] as an answer!
Incremented element at index 1
[1, 4]
Combination found!
Added [1, 4] as an answer!
Incremented element at index 1
[1, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[2, 5]
Moved index to the right, and copied the value from the left
[2, 2]
Incremented element at index 1
[2, 3]
Combination found!
Added [2, 3] as an answer!
Incremented element at index 1
[2, 4]
Combination found!
Added [2, 4] as an answer!
Incremented element at index 1
[2, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[3, 5]
Moved index to the right, and copied the value from the left
[3, 3]
Incremented element at index 1
[3, 4]
Combination found!
Added [3, 4] as an answer!
Incremented element at index 1
[3, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[4, 5]
Moved index to the right, and copied the value from the left
[4, 4]
Incremented element at index 1
[4, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[5, 5]
n exceeded at 0, moving index to the left
[[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
*/