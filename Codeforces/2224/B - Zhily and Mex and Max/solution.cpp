# include <iostream>
# include <vector>
# include <unordered_set>
# include <algorithm>
using namespace std;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;
        int nowMax = 0;
        int nowMex = 0;
        long long ans = 0;
        long long dup = 0;
 
        unordered_set<int> exist;
        vector<int> nums(n, 0);
        for (int i=0; i<n; i++){
            cin >> nums[i];
        }
 
        sort(nums.begin(), nums.end());
 
        int x = nums[n-1];
        exist.insert(x);
        nowMax = x;
        nowMex = (x ? 0 : 1);
        ans += nowMax + nowMex;
 
        for (int i=0; i<n-1; i++){
            x = nums[i];
            if ((exist.find(x) != exist.end())){
                dup++;
                continue;
            }
            exist.insert(x);
            
            while (exist.find(nowMex) != exist.end()){
                nowMex++;
            }
            ans += nowMax + nowMex;
        }
        ans += dup * (nowMax + nowMex);
        cout << ans << '\n';
    }
}