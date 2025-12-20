# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> happy(n, 0);
    vector<int> tired(n, 0);
    vector<int> max_happy(n, 0);
    vector<int> min_happy(n, 1<<30);
    vector<int> max_tired(n, 0);
    vector<int> min_tired(n, 1<<30);

    for (int i=0; i<n; i++){
        cin >> happy[i] >> tired[i];
        if (i==0){
            if (happy[i] != 0)
                min_happy[i] = happy[i];
            max_tired[i] = tired[i];
        }
        else{
            if (happy[i] != 0)
                min_happy[i] = min(happy[i], min_happy[i-1]);
            else
                min_happy[i] = min_happy[i-1];
            max_tired[i] = max(tired[i], max_tired[i-1]);
        }
    }
    for (int i=n-1; i>=0; i--){
        if (i == n-1){
            max_happy[i] = happy[i];
            if (tired[i] != 0)
                min_tired[i] = tired[i];
        }
        else{
            max_happy[i] = max(happy[i], max_happy[i+1]);
            if (tired[i] != 0)
                min_tired[i] = min(tired[i], min_tired[i+1]);
            else
                min_tired[i] = min_tired[i+1];
        }
    }
    int ans = -1;
    for (int i=n-2; i>=0; i--){
        if (min_happy[i] > max_happy[i+1] && max_tired[i] < min_tired[i+1]){
            ans = i;
            break;
        }
    }

    if (ans >= 0)
        cout << ans+1 << '\n';
    else
        cout << "-1\n";
}