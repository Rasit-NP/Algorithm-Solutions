# include <iostream>
# include <vector>
# include <unordered_set>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans = 6;
    cin >> n;
    vector<int> nums;
    unordered_set<int> set;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
        set.insert(a);
    }
    for (int num : nums){
        int cnt=0;
        for (int i=num+1; i<num+5; i++){
            if (set.find(i) == set.end()){
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}