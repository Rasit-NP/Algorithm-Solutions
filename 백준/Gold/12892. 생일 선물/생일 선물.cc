# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d;
    long long ans = 0;
    cin >> n >> d;
    vector<pair<long long, long long>> data(n, {0, 0});
    vector<long long> sums(n, 0);

    for (int i=0; i<n; i++){
        cin >> data[i].first >> data[i].second;
    }
    sort(data.begin(), data.end());
    for (int i=0; i<n; i++){
        if (i == 0){
            sums[i] = data[i].second;
            continue;
        }
        sums[i] = sums[i-1] + data[i].second;
    }
    for (int i=0; i<n; i++){
        int price = data[i].first;
        int target = price + d;
        int l = i, r = n;
        while (r-l>1){
            int mid = (l+r)/2;
            if (data[mid].first >= target){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        int idx = l;
        if (i==0){
            ans = max(ans, sums[idx]);
        }
        else{
            ans = max(ans, sums[idx]-sums[i-1]);
        }
    }
    cout << ans << endl;
}