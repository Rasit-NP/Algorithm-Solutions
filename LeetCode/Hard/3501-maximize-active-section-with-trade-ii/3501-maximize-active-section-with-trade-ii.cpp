# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        vector<int> gStart, gLen, grp(n, -1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    gLen.back()++;
                else {
                    gStart.push_back(i);
                    gLen.push_back(1);
                }
            }
            grp[i] = (int)gStart.size() - 1;
        }

        int G = gStart.size();
        if (G == 0)
            return vector<int>(queries.size(), ones);

        int m = G - 1;
        vector<int> merge_(max(m, 1), 0);

        for (int g = 0; g < m; g++)
            merge_[g] = gLen[g] + gLen[g + 1];

        int LOG = 1;
        while ((1 << LOG) <= max(m, 1))
            LOG++;

        vector<vector<int>> st(LOG, vector<int>(max(m, 1), 0));
        for (int j = 0; j < m; j++)
            st[0][j] = merge_[j];
        for (int i = 1; i < LOG; i++){
            for (int j = 0; j + (1 << i) <= m; j++)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }

        auto queryMax = [&](int l, int r) {
            int k = 31 - __builtin_clz(r - l + 1);
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };
        
        vector<int> ans; ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1], best = ones;
            int left  = (grp[l] == -1) ? -1 : (gLen[grp[l]] - (l - gStart[grp[l]]));
            int right = (grp[r] == -1) ? -1 : (r - gStart[grp[r]] + 1);
            int gl = grp[l] + 1;
            int gr = (s[r] == '1') ? grp[r] : grp[r] - 1;
            int startAdj = gl, endAdj = gr - 1;
            if (s[l] == '0' && s[r] == '0' && grp[l] + 1 == grp[r])
                best = max(best, ones + left + right);
            else if (startAdj <= endAdj)
                best = max(best, ones + queryMax(startAdj, endAdj));
            if (s[l] == '0' && grp[l] + 1 <= gr)
                best = max(best, ones + left + gLen[grp[l] + 1]);
            if (s[r] == '0' && grp[l] < grp[r] - 1)
                best = max(best, ones + right + gLen[grp[r] - 1]);
            ans.push_back(best);
        }
        return ans;
    }
};