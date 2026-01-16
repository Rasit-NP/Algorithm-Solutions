# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int w, n;   cin >> w >> n;
    vector<int> nums(n, 0);
    vector<pair<int, int>> sums(400001, {0, 0});
    vector<bool> has_sum(400001, false);
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            int now_sum = nums[i] + nums[j];
            int target = w - now_sum;
            if (target > 0 && target <= 400000 && has_sum[target]){
                if (i != sums[target].first && j != sums[target].first && i != sums[target].second && j != sums[target].second){
                    cout << "YES\n";
                    return 0;
                }
            }
        }
        for (int k=0; k<i; k++){
            if (i != k){
                has_sum[nums[i] + nums[k]] = true;
                sums[nums[i] + nums[k]] = {i, k};
            }
        }
    }
    cout << "NO\n";
    return 0;
}