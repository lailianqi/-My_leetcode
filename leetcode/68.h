#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> results;
        for (int i = 0, j = 0; i < words.size(); i = j) {
            int width = 0;
            for (j = i; j < words.size() && width + words[j].length() + j - i <= maxWidth; j++) {
                width += words[j].length();
            }
            int space = 1, extraSpace = 0;
            if (j - i != 1 && j != words.size()) {
                space = (maxWidth - width) / (j - i - 1);
                extraSpace = (maxWidth - width) % (j - i - 1);
            }
            string result = words[i];
            for (int k = i + 1; k < j; k++) {
                result += string(space, ' ');
                if (extraSpace-- > 0)
                    result += " ";
                result += words[k];
            }
            result += string(maxWidth - result.size(), ' ');
            results.push_back(result);
        }
        return results;
    }
};