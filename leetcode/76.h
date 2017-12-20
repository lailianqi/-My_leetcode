#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
using namespace std;

/*
Given a string S and a string T, find the minimum window in S which will contain
all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/
// https://leetcode.com/problems/minimum-window-substring/#/discuss
// https://discuss.leetcode.com/category/84/minimum-window-substring
//参考的答案
class Solution {
  public:
    string minWindow(string s, string t) {
        vector<int> dirctionary(128, 0);
        int begin = 0, end = 0, counter = t.size();
        int distance = INT_MAX, head = 0;
        for (auto c : t)
            dirctionary[c]++;
        while (end < s.length()) {
            if (dirctionary[s[end++]]-- > 0)
                counter--;
            while (counter == 0) {
                if (distance > (end - begin)) {
                    distance = end - begin;
                    head = begin;
                }
                if (dirctionary[s[begin++]]++ == 0)
                    counter++;
            }
        }
        return distance == INT_MAX ? "" : s.substr(head, distance);
    }
};

// Here comes the template.
// For most substring problem, we are given a string and need to find a
// substring of it which satisfy some restrictions. A general way is to use a
// hashmap assisted with two pointers. The template is given below.

// int findSubstring(string s){
//         vector<int> map(128,0);
//         int counter; // check whether the substring is valid
//         int begin=0, end=0; //two pointers, one point to tail and one  head
//         int d; //the length of substring

//         for(;;) { /* initialize the hash map here */ }

//         while(end<s.size()){

//             if(map[s[end++]]-- ?){  /* modify counter here */ }

//             while(/* counter condition */){

//                  /* update d here if finding minimum*/

//                 //increase begin to make it invalid/valid again

//                 if(map[s[begin++]]++ ?){ /*modify counter here*/ }
//             }

//             /* update d here if finding maximum*/
//         }
//         return d;
//   }

class Solution_0 {
  public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> dirctionary(128, 0);
        int begin = 0, end = 0, counter = 0;
        int distance = -1;
        while (end < s.length()) {
            if (dirctionary[s[end++]]++ == 0)
                counter++;
            while (counter > 2) {
                if (dirctionary[s[begin++]]-- == 1)
                    counter--;
            }
            distance = max(end - begin, distance);
        }
        return distance;
    }
};

void test() {
    Solution_0 s;
    cout << s.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
}