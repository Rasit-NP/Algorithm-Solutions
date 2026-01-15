# include <iostream>
# include <vector>
using namespace std;

int n, p, q, r;
long long s;
vector<int> scores;

bool judge(int k){
    long long sum = 0;
    for (int i=0; i<n; i++){
        if (scores[i] > k + r){
            sum += scores[i] - p;
        }
        else if (scores[i] < k){
            sum += scores[i] + q;
        }
        else {
            sum += scores[i];
        }
    }
    if (sum < s){
        return false;
    }
    else {
        return true;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    scores.assign(n, 0);
    int maximum = 0;
    for (int i=0; i<n; i++){
        cin >> scores[i];
        maximum = max(maximum, scores[i]);
    }
    cin >> p >> q >> r >> s;

    int l=-1, r = maximum + 1;
    while (r-l > 1){
        int mid = (l+r)/2;
        if (judge(mid)){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if (judge(r)){
        cout << max(1, r) << '\n';
    }
    else {
        cout << "-1\n";
    }
}