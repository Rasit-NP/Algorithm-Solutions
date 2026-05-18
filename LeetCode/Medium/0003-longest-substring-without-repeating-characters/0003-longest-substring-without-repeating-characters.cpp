# include <string>
# include <unordered_set>
# include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;

        for (int i=0; i<n; i++){
            unordered_set<char> visited;
            int cnt = 0;
            for (int j=i; j<n; j++){
                char let = s[j];
                if (visited.find(let) == visited.end()){
                    ++cnt;
                    visited.insert(let);
                }
                else {
                    break;
                }
            }
            res = max(res, cnt);
        }

        return res;
    }
};