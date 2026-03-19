# include <iostream>
# include <vector>
using namespace std;

bool check(int& x){
    int num = x;
    int s = 0;
    while (num){
        s += num%10;
        num /= 10;
    }

    if (x%s == 0){
        return true;
    }
    else {
        return false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int m, k;   cin >> m >> k;
    vector<int> nums(0);
    vector<int> dp(m+1, 0);
    dp[0] = 1;

    for (int i=1; i<=m; i++){
        if (check(i)){
            nums.push_back(i);
        }
    }
    for (int i=nums.size()-1; i>=0; i--){
        int num = nums[i];
        for (int j=0; j<=m-num; j++){
            dp[num+j] += dp[j];
            dp[num+j] %= k;
        }
    }
    cout << dp[m];
}