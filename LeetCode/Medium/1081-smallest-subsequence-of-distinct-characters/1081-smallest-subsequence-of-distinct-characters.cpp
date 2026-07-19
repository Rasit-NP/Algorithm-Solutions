# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int len = s.size();
        vector<int> cnt(26, 0), visited(26, 0);
        string res = "";

        for (char c : s){
            ++cnt[c-'a'];
        }

        for (char c : s){
            int idx = c-'a';
            while (res.size() && !visited[idx] && res.back() > c && cnt[res.back()-'a']){
                visited[res.back()-'a'] = 0;
                res.pop_back();
            }
            if (!visited[idx]){
                res.push_back(c);
                visited[idx] = 1;
            }
            --cnt[idx];
        }

        return res;
    }
};