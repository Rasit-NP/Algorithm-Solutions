# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    long long y0 = 0, cnt=0;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i=0; i<n; i++){
        cin >> nums[i];
        y0 = max(y0, nums[i]-(long long)k*i);
    }
    for (int i=0; i<n; i++){
        cnt += (long long)k*i + y0 - nums[i];
    }
    cout << cnt << '\n';
}