# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans=0;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> sorted(n, 0);
    vector<int> go_to(n, 0);
    for (int i=0; i<n; i++){
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted.begin(), sorted.end());
    for (int i=0; i<n; i++){
        go_to[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
    }
    for (int i=0; i<n;){
        if (go_to[i] == i){
            i++;
            continue;
        }
        swap(go_to[i], go_to[go_to[i]]);
        ans++;
    }
    cout << ans << '\n';
}