# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    long long u, o, s;  cin >> u >> o >> s;
    long long l = min(u, min(o, s));
    long long r = max(u, max(o, s));
    long long diff;
    while (r-l > 1){
        long long mid = (l+r)/2;
        if (u < mid){
            r = mid;
            continue;
        }
        if (mid > o){
            r = mid;
            continue;
        }
        diff = (u-mid)/2;
        if (s+diff < mid){
            r = mid;
            continue;
        }
        l = mid;
    }
    cout << l << '\n';
}