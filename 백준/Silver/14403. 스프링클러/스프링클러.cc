# include <iostream>
# include <algorithm>
# include <vector>
# include <climits>
using namespace std;

int n, x1, y_, x2, y2;

long long rad1(long long x, long long y){
    return (x-x1)*(x-x1) + (y-y_)*(y-y_);
}

long long rad2(long long x, long long y){
    return (x-x2)*(x-x2) + (y-y2)*(y-y2);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> x1 >> y_ >> x2 >> y2;

    long long max1 = 0, max2 = 0;
    vector<pair<long long, long long>> positions;

    for (int i=0; i<n; i++){
        int x, y;   cin >> x >> y;
        long long r1 = rad1(x, y), r2 = rad2(x, y);
        positions.push_back({r1, r2});
    }

    sort(positions.begin(), positions.end());

    long long ans = LONG_LONG_MAX;

    for (int i=-1; i<n; i++){
        long long max1 = 0, max2 = 0;
        if (i >= 0){
            max1 = positions[i].first;
        }
        for (int j=i+1; j<n; j++){
            max2 = max(max2, positions[j].second);
        }
        ans = min(ans, max1+max2);
    }
    cout << ans;
}