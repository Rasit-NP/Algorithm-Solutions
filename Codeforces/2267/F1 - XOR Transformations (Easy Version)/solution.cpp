# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
 
void solve();
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    while (t--){
        solve();
    }
}
 
void solve(){
    int n, q;  cin >> n >> q;
 
    vector<int> nums(n, 0);
    for (int i=0; i<n; ++i){
        cin >> nums[i];
    }
 
    sort(nums.begin(), nums.end());
 
    vector<int> queries(q, 0);
    for (int i=0; i<q; ++i){
        cin >> queries[i];
    }
 
    vector<int> memo;
    memo.emplace_back(nums[n-1] - nums[0]);
 
    while (nums[n-1]){
        priority_queue<int> pq;
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                int val = nums[i] ^ nums[j];
                if (pq.size() < n){
                    pq.push(val);
                }
                else if (pq.top() > val){
                    pq.pop();
                    pq.push(val);
                }
            }
        }
 
        for (int id=n-1; id>=0; --id){
            nums[id] = pq.top();    pq.pop();
        }
 
        memo.emplace_back(nums.back() - nums.front());
    }
 
    for (int x : queries){
        if (x >= memo.size()){
            cout << "0\n";
        }
        else {
            cout << memo[x] << '\n';
        }
    }
}