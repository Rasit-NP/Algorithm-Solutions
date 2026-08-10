# include <vector>
# include <algorithm>
using namespace std;
typedef long long llong;

llong solution(int n, vector<int> works) {
    llong res = 0;
    
    int l = 0, r = 50000;
    while (r-l > 1){
        int mid = (l+r)/2;
        llong diff = 0;
        for (int work : works){
            diff += work - min(work, mid);
        }
        if (diff > (llong)n)
            l = mid;
        else
            r = mid;
    }
    
    llong diff = 0;
    for (int work : works){
        diff += work - min(work, r);
    }
    
    int offset = n - diff;
    for (int work : works){
        work = min(work, r);
        if (offset && work==r){
            work = max(0, work-1);
            --offset;
        }

        res += (llong)work * work;
    }
    
    return res;
}