# include <string>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string res = s;
        int cnt[26] = {0};

        for (char c : s){
            ++cnt[c-'a'];
        }

        int idx = 0;

        for (int i=0; i<26; ++i){
            char c = i + 'a';
            while (cnt[i] >= 2){
                res[idx] = c;
                res[n-idx-1] = c;
                cnt[i] -= 2;
                ++idx;
            }
            if (cnt[i] == 1){
                s[n/2] = c;
            }
        }

        return res;
    }
};