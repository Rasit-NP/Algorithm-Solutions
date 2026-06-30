# include <string>
# include <queue>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
public:
    int numberOfSubstrings(string s) {
        n = s.size();

        int res = 0;
        int last[3] = {-1, -1, -1};

        for(int i=0; i<n; i++){
            char let = s[i];

            last[let-'a'] = i;

            if (last[0] != -1 && last[1] != -1 && last[2] != -1){
                res += min({last[0], last[1], last[2]}) + 1;
            }
        }

        return res;
    }
};