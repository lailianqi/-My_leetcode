#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
//第一题
//比赛中这题成功的ac
class Solution {
  public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        map<int, int> dir;
        vector<int> res;
        for (int i = 0; i < B.size(); i++) {
            dir[B[i]] = i;
        }
        for (int i = 0; i < A.size(); i++) {
            res.push_back(dir[A[i]]);
        }
        return res;
    }
};
//第二题
class Solution_0 {
  public:
    //解法错误 过不了ac
    string boldWords(vector<string> &words, string S) {
        int start = S.size() - 1, end = 0;
        for (int i = 0; i < words.size(); i++) {
            if (S.find(words[i]) != -1) {
                start = min(start, (int)S.find(words[i]));
                end = max(end, (int)(S.find(words[i]) + words[i].size()));
            }
        }
        return S.substr(0, start) + "<b>" + S.substr(start, end - start) +
               "</b>" + S.substr(end, S.size());
    }
    // LeetCode论坛的人的写法 自己把它改为c++的解法 下面是原贴的地址
    // https://discuss.leetcode.com/topic/116284/clean-java-solution-using-only-boolean-array-and-stringbuilder
    string boldWords1(vector<string> &words, string S) {
        vector<bool> marked(S.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            markWords(S, words[i], marked);
        }
        string res;
        for (int i = 0; i < S.size(); i++) {
            if (marked[i] && (i == 0 || !marked[i - 1])) {
                res += "<b>";
            }
            res.push_back(S[i]);
            if (marked[i] && (i == S.size() - 1 || !marked[i + 1])) {
                res += "</b>";
            }
        }
        return res;
    }
    void markWords(string &S, string &word, vector<bool> &marked) {
        for (int i = 0; i <= S.length() - word.length(); i++) {
            string substr = S.substr(i, word.size());
            if (word == substr) {
                for (int j = i; j < i + word.size(); j++) {
                    marked[j] = true;
                }
            }
        }
    }
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
//第三题
//比赛中这题成功的ac
class Solution_1 {
  public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &avails) {
        vector<Interval> temp;
        vector<Interval> res;
        for (int i = 0; i < avails.size(); i++) {
            for (int j = 0; j < avails[i].size(); j++) {
                temp.push_back(avails[i][j]);
            }
        }
        sort(temp.begin(), temp.end(),
             [](Interval &a, Interval &b) { return a.start < b.start; });
        Interval it(temp[0].start, temp[0].end);
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].start > it.end) {
                res.push_back(Interval(it.end, temp[i].start));
                it = temp[i];
            } else {
                it.end = max(it.end, temp[i].end);
            }
        }
        return res;
    }
};
// 这题比赛的时候没写出来 下面是LeetCode的答案
// https://discuss.leetcode.com/topic/116280/easy-and-concise-solution-with-explanation-c-java-python
class Solution_2 {
  public:
    string makeLargestSpecial(string S) {
        int count = 0, i = 0;
        vector<string> res;
        for (int j = 0; j < S.size(); j++) {
            S[j] == '1' ? count++ : count--;
            if (count == 0) {
                res.push_back(
                    '1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(res.begin(), res.end(), greater<string>());
        string res2 = "";
        for (int i = 0; i < res.size(); ++i)
            res2 += res[i];
        return res2;
    }
};

void test() {}