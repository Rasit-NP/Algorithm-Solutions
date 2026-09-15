# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n, k;
    string s;
    vector<vector<int>> palindrome;
    vector<vector<int>> ranges;

    void init(string& S, int K){
        s = std::move(S);
        n = s.size();
        k = K;

        palindrome.assign(n, vector<int>(n));
        for (int i=0; i<n; ++i){
            palindrome[i][i] = 1;
            if (i && s[i-1] == s[i])
                palindrome[i-1][i] = 1;
        }

        for (int len = 2; len<k+2; ++len){
            for (int i=0; i<n-len; ++i){
                if (!palindrome[i+1][i+len-1])
                    continue;
                if (s[i] == s[i+len])
                    palindrome[i][i+len] = 1;
            }
        }

        for (int i=0; i<n; ++i){
            for (int j=i+k-1; j<min(n, i+k+1); ++j){
                if (palindrome[i][j])
                    ranges.push_back({i, j});
            }
        }
    }
public:
    int maxPalindromes(string S, int K) {
        init(S, K);

        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b){
            return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
        });

        int res = 0;
        int lastEnd = -1;

        for (const auto& range : ranges){
            if (range[0] > lastEnd){
                ++res;
                lastEnd = range[1];
            }
        }

        return res;
    }
};