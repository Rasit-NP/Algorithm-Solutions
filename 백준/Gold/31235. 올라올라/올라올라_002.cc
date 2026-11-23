# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<int> nums(n, 0);
    
    for (int i=0; i<n; ++i){
        cin >> nums[i];
    }

    int baseIdx = 0;
    int baseVal = nums[baseIdx];
    int res = 0;

    for (int i=1; i<n; ++i){
        int val = nums[i];
        if (val >= baseVal){
            res = max(res, i-baseIdx);
            baseVal = val;
            baseIdx = i;
        }
    }

    res = max(res, n-baseIdx);

    cout << res << '\n';
}