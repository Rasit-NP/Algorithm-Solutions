# include <iostream>
# include <vector>
using namespace std;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;
        int res = 0;
        vector<long long> nums(n, 0);
        for (int i=0; i<n; i++){
            cin >> nums[i];
        }
 
        for (int i=n-1; i>=0; i--){
            if (i && (nums[i] > 0)){
                nums[i-1] += nums[i];
            }
            res += (nums[i] > 0 ? 1 : 0);
        }
 
        cout << res << '\n';
    }
}