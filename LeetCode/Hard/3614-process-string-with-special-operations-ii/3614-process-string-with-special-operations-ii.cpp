# include <string>
# include <algorithm>
typedef long long llong;
using namespace std;

class Solution {
private:
    llong getFinalLenth(string& s){
        llong len = 0;
        for (char let : s){
            if (let == '#'){
                len <<= 1;
            }
            else if (let == '*'){
                if (len)
                    --len;
            }
            else if (let == '%'){
                continue;
            }
            else {
                ++len;
            }
        }
        return len;
    }
public:
    char processStr(string s, llong k) {
        bool isReverse = false;
        llong nowLen = getFinalLenth(s);
        llong nowIdx = k;
        int n = s.size();
        if (k >= nowLen){
            return '.';
        }
        for (int i=n-1; i>=0; --i){
            char let = s[i];
            if (let >= 'a' && let <= 'z'){
                if (nowLen == nowIdx + 1){
                    return let;
                }
                --nowLen;
            }
            else if (let == '*'){
                ++nowLen;
            }
            else if (let == '#'){
                nowLen >>= 1;
                if (nowIdx >= nowLen){
                    nowIdx -= nowLen;
                }
            }
            else if (let == '%'){
                nowIdx = nowLen - nowIdx - 1;
            }
        }
        return 0;
    }
};