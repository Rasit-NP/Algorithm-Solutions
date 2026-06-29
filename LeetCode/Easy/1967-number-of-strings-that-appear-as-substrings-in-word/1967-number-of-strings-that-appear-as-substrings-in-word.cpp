# include <string>
# include <vector>
using namespace std;

class Solution {
private:
    int wordLen;
    string word;
    int check(string& pattern){
        int len = pattern.size();
        for (int i=0; i<wordLen-len+1; ++i){
            bool res = true;
            for (int idx=0; idx<len; ++idx){
                if (word[i+idx] != pattern[idx]){
                    res = false;
                    break;
                }
            }
            if (res){
                return 1;
            }
        }
        return 0;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        this->word = word;
        wordLen = word.size();
        int res = 0;
        for (string pattern : patterns){
            res += check(pattern);
        }

        return res;
    }
};