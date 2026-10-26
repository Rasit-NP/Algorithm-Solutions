# include <vector>
# include <algorithm>
using namespace std;

int solution(vector<int> sticker) {
    int n = sticker.size();
    
    if (n == 1)
        return sticker[0];
    
    vector<pair<int, int>> dp1(n);
    vector<pair<int, int>> dp2(n);
    
    dp1[0] = {sticker[0], 0};
    dp1[1] = {0, sticker[0]};
    dp2[1] = {sticker[1], 0};
    
    for (int i=2; i<n; ++i){
        dp1[i].first = max(max(dp1[i-2].first, dp1[i-2].second), dp1[i-1].second) + sticker[i];
        dp1[i].second = max(dp1[i-1].first, dp1[i-1].second);
        
        dp2[i].first = max(max(dp2[i-2].first, dp2[i-2].second), dp2[i-1].second) + sticker[i];
        dp2[i].second = max(dp2[i-1].first, dp2[i-1].second);
    }
    
    dp1[n-1].first = 0;
    
    return max(dp1[n-1].second, max(dp2[n-1].first, dp2[n-1].second));
}