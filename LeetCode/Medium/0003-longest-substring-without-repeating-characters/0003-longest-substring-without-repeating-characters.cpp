# include <string>
# include <unordered_map>
# include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        unordered_map<char, int> latest;

        for (int head=-1, tail=0; tail<n; tail++){
            char let = s[tail];
            if (latest.find(let) == latest.end()){
                latest[let] = tail;
            }
            else {
                if (latest[let] > head){
                    head = latest[let];
                }
                latest[let] = tail;
            }
            res = max(tail-head, res);
        }

        return res;
    }
};