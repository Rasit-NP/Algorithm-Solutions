# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void solve(int);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    for (int tc=1; tc<=t; tc++){
        solve(tc);
    }
}

void solve(int tc){
    int n;  cin >> n;
    vector<int> nums(n);
    int total = 0;
    for (int i=0; i<n; i++){
        cin >> nums[i];
        total += nums[i];
    }
    sort(nums.begin(), nums.end());

    vector<int> able(total+1, 0);
    able[0] = 1;
    for (int i=n-1; i>=0; --i){
        int score = nums[i];
        for (int base=total-score; base>=0; --base){
            if (able[base]){
                able[base+score] = 1;
            }
        }
    }

    int cnt = 0;
    for (int val : able){
        if (val){
            ++cnt;
        }
    }

    printf("#%d %d\n", tc, cnt);
}
