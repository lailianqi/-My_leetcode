#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
//没有按顺序的分类方案，自己写的
class Solution {
  public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> >answers;
        map<string, vector<string> > maps;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            maps[s].push_back(strs[i]);
        }
        for (map<string, vector<string> >::iterator it = maps.begin(); it != maps.end(); it++) {
            answers.push_back(it->second);
        }
        return answers;
    }
};

//leetcode参考答案
class Solution_0 {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string> > mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string> > anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};

//Solution_0的优化版  https://discuss.leetcode.com/topic/21038/10-lines-76ms-easy-c-solution-updated-function-signature/20
class Solution_1 {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string> > mp;
        for (string s : strs) {
            string t = strSort(s);
            mp[t].insert(s);
        }
        vector<vector<string> > anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
private:
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
};