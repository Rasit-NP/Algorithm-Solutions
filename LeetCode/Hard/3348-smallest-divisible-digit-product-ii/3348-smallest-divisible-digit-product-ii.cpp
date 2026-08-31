#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long llong;

class Solution {
private:
    string now = "";
    string res = "";
    vector<int> cntPrime;
    vector<vector<int>> dp;
    int MAXE2 = 50, MAXE3 = 33;

    void buildDP() {
        dp.assign(MAXE2 + 1, vector<int>(MAXE3 + 1, 0));
        int f2[6] = {1, 0, 2, 1, 3, 0};
        int f3[6] = {0, 1, 0, 1, 0, 2};
        for (int a = 0; a <= MAXE2; a++) {
            for (int b = 0; b <= MAXE3; b++) {
                if (a == 0 && b == 0) {
                    dp[a][b] = 0;
                    continue;
                }
                int best = 1e9;
                for (int k = 0; k < 6; k++) {
                    int pa = max(a - f2[k], 0);
                    int pb = max(b - f3[k], 0);
                    if (pa == a && pb == b)
                        continue;
                    best = min(best, 1 + dp[pa][pb]);
                }
                dp[a][b] = best;
            }
        }
    }

    void change(char c, int sign) {
        switch (c) {
            case '2':
                cntPrime[2] += sign;
                break;
            case '3':
                cntPrime[3] += sign;
                break;
            case '4':
                cntPrime[2] += 2 * sign;
                break;
            case '5':
                cntPrime[5] += sign;
                break;
            case '6':
                cntPrime[2] += sign;
                cntPrime[3] += sign;
                break;
            case '7':
                cntPrime[7] += sign;
                break;
            case '8':
                cntPrime[2] += 3 * sign;
                break;
            case '9':
                cntPrime[3] += 2 * sign;
                break;
        }
    }

    int minDigitsNeeded() {
        int e2 = min(max(cntPrime[2], 0), MAXE2);
        int e3 = min(max(cntPrime[3], 0), MAXE3);
        int e5 = max(cntPrime[5], 0);
        int e7 = max(cntPrime[7], 0);
        return dp[e2][e3] + e5 + e7;
    }

    void solve(const string& num, int target, bool tight) {
        if ((int)now.size() == target) {
            bool done = cntPrime[2] < 1 && cntPrime[3] < 1 && cntPrime[5] < 1 && cntPrime[7] < 1;
            if (done) {
                res = now;
            }
            return;
        }
        if (target - (int)now.size() < minDigitsNeeded()) {
            return;
        }

        int len = now.size();
        char start;
        if (tight && len < (int)num.size()) {
            start = num[len];
            if (start < '1') start = '1';
        } else {
            start = '1';
        }
        for (char c = start; c <= '9'; c++) {
            now.push_back(c);
            change(c, -1);
            bool sameDigit = tight && len < (int)num.size() && c == num[len];
            solve(num, target, sameDigit);
            if ((int)res.size() == target) {
                change(c, 1);
                now.pop_back();
                return;
            }
            change(c, 1);
            now.pop_back();
        }
    }

public:
    string smallestNumber(string num, llong t) {
        cntPrime.assign(8, 0);

        for (int p : {2, 3, 5, 7}) {
            while (t % p == 0) {
                cntPrime[p]++;
                t /= p;
            }
        }

        if (t > 1) {
            return "-1";
        }

        buildDP();

        int n = num.size();
        vector<int> base = cntPrime;
        int minLen = minDigitsNeeded();

        if (n >= minLen) {
            now.clear();
            res.clear();
            now.reserve(n);
            cntPrime = base;
            solve(num, n, true);
            if (!res.empty()) {
                return res;
            }
        }

        int target = max(n + 1, minLen);
        cntPrime = base;
        now.clear();
        res.clear();
        now.reserve(target);
        solve(num, target, false);
        return res;
    }
};