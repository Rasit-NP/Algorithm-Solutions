# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        vector<int> cnt(26);

        for (char c : word){
            ++cnt[c-'a'];
        }

        sort(cnt.begin(), cnt.end(), [](int a, int b){
            if (a > b)
                return true;
            else
                return false;
        });

        for (int i=0, t=1; i<26; t += ((++i)%8 == 0)){
            res += t * cnt[i];
        }

        return res;
    }
};