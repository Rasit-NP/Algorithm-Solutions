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
        vector<int> chunks;

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
            }
            nowLen = 1;
        }

        int sz = chunks.size();
        if (sz == 0){
            return len-2;
        }
        else if (sz == 1){
            return len-chunks[0]-2;
        }

        int val = 0;
        for (int i=1; i<sz; i++){
            val = max(val, chunks[i-1] + chunks[i]);
        }

        return oneCnt + val;
    }
};