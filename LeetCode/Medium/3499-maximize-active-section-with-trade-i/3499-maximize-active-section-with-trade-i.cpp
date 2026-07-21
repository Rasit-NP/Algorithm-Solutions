# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s.push_back('1');
        int n = s.size();
        int oneCnt = s[0] - '0';
        int maxVal = 0;
        int before0 = 0;
        int nowLen = 1;
        
        for (int i=1; i<n; i++){
            if (s[i] == '1'){
                ++oneCnt;
            }
            if (s[i-1] == s[i]){
                ++nowLen;
            }
            else {
                if (s[i] == '1'){
                    if (before0)
                        maxVal = max(maxVal, before0 + nowLen);
                    before0 = nowLen;
                }
                nowLen = 1;
            }
        }

        return oneCnt + maxVal - 1;
    }
};