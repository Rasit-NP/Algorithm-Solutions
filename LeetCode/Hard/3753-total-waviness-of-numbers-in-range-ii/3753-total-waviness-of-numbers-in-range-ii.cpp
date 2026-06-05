# include <vector>
# include <string>
typedef long long llong;
using namespace std;

class Solution {
private:
    int l;
    vector<int> digits;
    pair<llong, llong> memo[20][11][11][2];
    bool seen[20][11][11][2];

    pair<llong, llong> solve(int pos, int prev2, int prev1, bool started, bool tight){
        if (pos == l) return {1, 0};
        if (!tight && seen[pos][prev2][prev1][started])
            return memo[pos][prev2][prev1][started];

        int hi = tight ? digits[pos] : 9;
        llong cnt = 0, total = 0;
        for (int d=0; d<=hi; d++){
            bool nstarted = started || (d != 0);

            int flag = 0;
            if (started && prev2 != 10 && prev1 != 10){
                if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d))
                    flag = 1;
            }

            int nprev2, nprev1;
            if (!nstarted){
                nprev2 = 10;
                nprev1 = 10;
            }
            else {
                nprev2 = prev1;
                nprev1 = d;
            }

            bool ntight = tight && (d == hi);
            auto sub = solve(pos+1, nprev2, nprev1, nstarted, ntight);
            cnt += sub.first;
            total += sub.second + (llong)flag * sub.first;
        }

        if (!tight){
            seen[pos][prev2][prev1][started] = true;
            memo[pos][prev2][prev1][started] = {cnt, total};
        }
        return {cnt, total};
    }
    llong count(llong num){
        if (num < 0)
            return 0;
        
        string s = to_string(num);
        l = (int)s.size();
        digits.assign(s.begin(), s.end());

        for (auto& c: digits)
            c -= '0';
        memset(seen, 0, sizeof(seen));

        return solve(0, 10, 10, false, true).second;
    }
public:
    llong totalWaviness(llong num1, llong num2) {
        return count(num2) - count(num1-1);
    }
};