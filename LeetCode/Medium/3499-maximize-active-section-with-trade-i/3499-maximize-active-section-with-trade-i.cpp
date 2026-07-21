# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string arg = "1" + s + "1";
        int len = arg.size();
        int oneCnt = 0;
        int sz = 0;
        vector<int> chunks;

        int val = 0;

        for (int i=1; i<len; i++){
            static int nowLen = 1;
            if (i<len-1 && arg[i] == '1'){
                ++oneCnt;
            }
            if (arg[i-1] == arg[i]){
                ++nowLen;
                continue;
            }
            if (arg[i] == '1'){
                chunks.emplace_back(nowLen);
                if (++sz > 1){
                    val = max(val, chunks.back() + chunks[sz-2]);
                }
            }
            nowLen = 1;
        }

        return oneCnt + val;
    }
};