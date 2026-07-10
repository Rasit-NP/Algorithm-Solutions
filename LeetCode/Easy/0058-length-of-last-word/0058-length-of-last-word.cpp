# include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int cnt = 0;

        for (char c : s){
            if (c == ' '){
                if (cnt)
                    res = cnt;
                cnt = 0;
            }
            else {
                ++cnt;
            }
        }
        if (cnt)
            res = cnt;

        return res;
    }
};