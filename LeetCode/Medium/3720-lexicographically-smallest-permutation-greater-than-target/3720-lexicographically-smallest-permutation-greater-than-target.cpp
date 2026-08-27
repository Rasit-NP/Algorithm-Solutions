# include <string>
using namespace std;


class Solution {
private:
    int cnt[26] = {0};
    string target;
    string now = "", res = "";

    void backtrack(){
        if (now.size() == target.size()){
            if (now > target){
                res = now;
            }
            return;
        }

        int i = now.size();
        string cmp = target.substr(0, i);
        if (cmp < now){
            for (char c='a'; c<='z'; c++){
                if (cnt[c-'a']){
                    --cnt[c-'a'];
                    now.push_back(c);
                    backtrack();
                    if (res.size())
                        return;
                    now.pop_back();
                    ++cnt[c-'a'];
                }
            }
        }
        else if (cmp == now){
            for (char c=target[i]; c<='z'; c++){
                if (cnt[c-'a']){
                    --cnt[c-'a'];
                    now.push_back(c);
                    backtrack();
                    if (res.size())
                        return;
                    now.pop_back();
                    ++cnt[c-'a'];
                }
            }
        }
        else {
            return;
        }
    }
public:
    string lexGreaterPermutation(string s, string target) {
        this->target = target;
        for (char c : s)
            ++cnt[c-'a'];

        backtrack();

        return res;
    }
};