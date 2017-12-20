#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
  public:
    vector<string> v;
    map<char, string> digitToCharFunction() {
        map<char, string> container;
        container['2'] = "abc";
        container['3'] = "def";
        container['4'] = "ghi";
        container['5'] = "jkl";
        container['6'] = "mno";
        container['7'] = "pqrs";
        container['8'] = "tuv";
        container['9'] = "wxyz";
        return container;
    }
    // 递归 效率不高
    vector<string> letterCombinations(string digits) {
        map<char, string> container = digitToCharFunction();
        if (digits.size() == 0) {
            return v;
        }
        analysis(digits, "", 0, container);
        return v;
    }
    void analysis(string digits, string s1, int depth,
                  map<char, string> container) {
        if (depth == digits.size()) {
            v.push_back(s1);
            return;
        }
        char s = digits[depth];
        string temp = s1;
        string p = container[s];
        for (int i = 0; i < p.size(); i++) {
            s1 += p[i];
            analysis(digits, s1, depth + 1, container);
            s1 = temp;
        }
    }
    vector<string> letterCombinations1(string digits) {
        map<char, string> container = digitToCharFunction();
        queue<string> resultQueue;
        vector<string> result;
        if (digits.size() == 0)
            return result;
        resultQueue.push("");
        for (int i = 0; i < digits.size(); i++) {
            string s = resultQueue.front();
            while (s.size() == i) {
                resultQueue.pop();
                for (char c : container[digits[i]]) {
                    resultQueue.push(s + c);
                }
                s = resultQueue.front();
            }
        }
        while (!resultQueue.empty()) {
            result.push_back(resultQueue.front());
            resultQueue.pop();
        }
        return result;
    }
};

void test() {
    Solution s;
    vector<string> v = s.letterCombinations1("23");
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

// unordered_map<char, string> digitToString = {
//     {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
//     {'6', "mno"}, {'7', "pqrs"}, {'8', "tyv"}, {'9', "wxyz"}};