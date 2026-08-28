# include <string>
using namespace std;

class Solution {
private:
    int n;
    string target;
    int cnt[26];
    int half;
    char midChar;
    bool hasMid;

    string build(const string& p) {
        string res = p;
        if (hasMid) {
            res += midChar;
        }
        for (int i = half - 1; i >= 0; i--) {
            res += p[i];
        }
        return res;
    }

    bool dfs(int pos, bool tight, string& cur, string& res) {
        if (pos == half) {
            string full = build(cur);
            if (full > target) {
                res = full;
                return true;
            }
            return false;
        }
        int lo = tight ? (target[pos] - 'a') : 0;
        for (int c = lo; c < 26; c++) {
            if (cnt[c] < 2) {
                continue;
            }
            cnt[c] -= 2;
            cur[pos] = 'a' + c;
            bool ntight = tight && (c == target[pos] - 'a');
            if (dfs(pos + 1, ntight, cur, res)) {
                cnt[c] += 2;
                return true;
            }
            cnt[c] += 2;
        }
        return false;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        n = s.size();
        this->target = target;
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }
        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        int odd = 0;
        int oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                oddChar = i;
            }
        }
        if (n % 2 == 0 && odd != 0) {
            return "";
        }
        if (n % 2 == 1 && odd != 1) {
            return "";
        }

        half = n / 2;
        hasMid = (n % 2 == 1);
        if (hasMid) {
            midChar = 'a' + oddChar;
            cnt[oddChar]--;
        }

        string cur(half, ' ');
        string res = "";
        dfs(0, true, cur, res);
        return res;
    }
};