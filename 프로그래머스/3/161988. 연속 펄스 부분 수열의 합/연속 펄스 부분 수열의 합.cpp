# include <vector>
# include <climits>
using namespace std;
typedef long long ll;

int n;

ll createAndCal(vector<int>& nums, int start){
    vector<int> vec(n, 0);
    for (int i=0; i<n; i++){
        if (i&1){
            vec[i] = nums[i] * start;
        }
        else {
            vec[i] = -nums[i] * start;
        }
    }
    vector<ll> newV(n, 0);
    newV[0] = vec[0];
    for (int i=1; i<n; i++){
        newV[i] = max((ll)0, newV[i-1]) + vec[i];
    }
    
    ll res = LONG_LONG_MIN;
    for (ll num : newV){
        res = max(res, num);
    }
    
    return res;
}

ll solution(vector<int> sequence) {
    n = sequence.size();
    ll res = LONG_LONG_MIN;
    res = max(res, createAndCal(sequence, 1));
    res = max(res, createAndCal(sequence, -1));
    
    return res;
}