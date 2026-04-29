# include <string>
# include <vector>
typedef long long llong;
using namespace std;

int sz;

llong isAble(int x, const vector<int>& diffs, const vector<int>& times){
    llong res = 0;
    for (int i=0; i<sz; ++i){
        int diff = diffs[i];
        int timeCur = times[i];
        if (i == 0){
            res += timeCur;
            continue;
        }
        int timePrev = times[i-1];
        if (x < diff){
            res += (timePrev + timeCur) * (diff-x);
        }
        res += timeCur;
    }
    
    return res;
}

int solution(vector<int> diffs, vector<int> times, llong limit) {
    sz = diffs.size();
    int l = 0, r = 100'000;
    
    while (r-l > 1){
        int mid = (l+r)/2;
        
        if (isAble(mid, diffs, times) <= limit){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    
    return r;
}