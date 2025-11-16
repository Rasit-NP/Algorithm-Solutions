# include <iostream>
# include <vector>
using namespace std;

int main(void){
    int t, n, i=0;
    vector<long long> banned;
    cin >> t >> n;
    for (; i<n; i++){
        int cnt, j=0;
        long long bit=0;
        cin >> cnt;
        for (; j<cnt; j++){
            int x;
            cin >> x;
            bit = bit | (long long) 1<<(--x);
        }
        banned.push_back(bit);
    }
    long long ans=0;
    for (i=0; i<((long long)1<<t); i++){
        bool check = true;
        for (int j=0; j<n; j++){
            if ((banned[j]&i) == banned[j]){
                check = false;
                break;
            }
        }
        if (check){
            ans++;
        }
    }
    printf("%lld\n", ans);
}