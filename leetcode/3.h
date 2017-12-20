#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
    public:
      int lengthOfLongestSubstring(string s) {
            int length = 0;
            map<char, int> charmap;
            for (int i = 0, j = 0; i < s.length(); i++) {
                  if (charmap.find(s[i]) != charmap.end()) {
                        j = max(j, charmap[s[i]] + 1);
                  }
                  // charmap.insert(pair<char, int>(s[i],i));
                  //新插入的键值与原有的键值重复则插入无效
                  charmap[s[i]] = i;
                  length = max(length, i - j + 1);
            }
            return length;
      }
};

void test() {
      Solution solution;
      string s;
      cin >> s;
      cout << solution.lengthOfLongestSubstring(s) << endl;
}

/*the basic idea is, keep a hashmap which stores the characters in string as
 * keys and their positions as values, and keep two pointers which define the
 * max substring. move the right pointer to scan through the string , and
 * meanwhile update the hashmap. If the character is already in the hashmap,
 * then move the left pointer to the right of the same character last found.
 * Note that the two pointers can only move forward.
*/