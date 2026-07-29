# include <vector>
# include <string>
# include <algorithm>
using namespace std;
typedef long long llong;

class Solution {
private:
    int n;
    int MAX;
    string res = "";
    vector<int> cnt;

    llong comb(int, int);

    llong calPerm(int, vector<int>&);

    void recurse(int k){
        int len = n/2 - res.size() - 1;
        for (int i=0; i<26; i++){
            if (cnt[i]){
                --cnt[i];
                long long val = calPerm(len, cnt);
                if (k <= val){
                    res.push_back('a'+i);
                    recurse(k);
                    break;
                }
                else {
                    k -= val;
                    ++cnt[i];
                }
            }
        }
    }
public:
    string smallestPalindrome(string s, int k) {
        n = s.size();
        MAX = k+1;
        cnt.assign(26, 0);
        res.reserve(n);

        for (int i=0, len=n/2; i<len; i++){
            ++cnt[s[i]-'a'];
        }

        if (k > calPerm(n/2, cnt)){
            return "";
        }

        recurse(k);

        if (n & 1){
            res.push_back(s[n/2]);
        }

        for (int i=n/2-1; i>=0; i--){
            res.push_back(res[i]);
        }

        return res;
    }
};

llong Solution::comb(int n, int r){
    llong res = 1;
    r = min(r, n-r);
    for (int i=0; i<r; i++){
        res *= (n-i);
        res /= (i+1);
        if (res >= MAX)
            break;
    }
    return res;
}

llong Solution::calPerm(int len, vector<int>& cnt){
    llong total = 1;
    for (int i=0; i<26; i++){
        if (cnt[i]){
            total *= comb(len, cnt[i]);
            len -= cnt[i];
        }
        if (total >= MAX)
            break;
    }

    return total;
}