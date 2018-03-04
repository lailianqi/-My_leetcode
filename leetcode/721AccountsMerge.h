#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 这题没写出来  这是一开始错误的思路
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<int, set<string>> dir;
        unordered_map<string, int> emailMap;
        unordered_map<string, int> nameMap;
        for (auto &element : accounts) {
            int id = isSamePerson(element, emailMap);
            if (id != -1) {
                for (int i = 1; i < element.size(); i++) {
                    emailMap[element[i]] = id;
                }
            }
        }
    }
    int isSamePerson(vector<string> &element,
                     unordered_map<string, int> &emailMap) {
        for (int i = 1; i < element.size(); i++) {
            if (emailMap.count(element[i])) {
                return emailMap[element[i]];
            }
        }
        return -1;
    }
};

// 来自LeetCode的答案 写的非常的好 是我学习的对象
// https://leetcode.com/problems/accounts-merge/discuss/109157/JavaC++-Union-Find/117437?page=1
class Solution_1 {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parents[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            string p = find(accounts[i][1], parents);
            for (int j = 2; j < accounts[i].size(); j++)
                parents[find(accounts[i][j], parents)] = p;
        }
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                unions[find(accounts[i][j], parents)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (auto &element : unions) {
            vector<string> emails(element.second.begin(), element.second.end());
            emails.insert(emails.begin(), owner[element.first]);
            res.push_back(emails);
        }
        return res;
    }
    string find(string s, map<string, string> &p) {
        return p[s] == s ? s : find(p[s], p);
    }
};

// DFS的解法
// https://leetcode.com/problems/accounts-merge/discuss/109161/Python-Simple-DFS-with-explanation!!!
class Solution_2 {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, vector<int>> emails_accounts_map;
        vector<vector<string>> res;
        vector<bool> visited(accounts.size(), false);
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                emails_accounts_map[accounts[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            if (visited[i]) {
                continue;
            }
            set<string> temp;
            helper(accounts, i, temp, visited, emails_accounts_map);
            vector<string> a(temp.begin(), temp.end());
            a.insert(a.begin(), accounts[i][0]);
            res.push_back(a);
        }
        return res;
    }
    void helper(vector<vector<string>> &accounts, int index, set<string> &email,
                vector<bool> &visited,
                unordered_map<string, vector<int>> &emails_accounts_map) {
        visited[index] = true;
        for (int j = 1; j < accounts[index].size(); j++) {
            email.insert(accounts[index][j]);
            for (auto neighbor : emails_accounts_map[accounts[index][j]]) {
                if (!visited[neighbor]) {
                    helper(accounts, neighbor, email, visited,
                           emails_accounts_map);
                }
            }
        }
    }
};