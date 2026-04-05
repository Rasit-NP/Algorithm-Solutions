# include <iostream>
# include <vector>
typedef long long llong;
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    llong sum = 0;
    llong target;
    vector<llong> nums(n, 0);

    for (llong& num : nums){
        cin >> num;
        sum += num;
    }
    
    target = sum/n;
    llong ans = 0;
    
    while(true){
        int correct = 0;
        for (int i=0; i<n; i++){
            llong& now = nums[i];
            if (now > target){
                llong& next = nums[(i+1<n ? i+1 : 0)];
                ans += now - target;
                next += now - target;
                now = target;
                correct++;
            }
            else if (now == target){
                correct++;
            }
        }

        if (correct == n){
            break;
        }
    }
    cout << ans;
}