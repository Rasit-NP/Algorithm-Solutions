# include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m;       cin >> n >> m;
    string s, t;    cin >> s >> t;
    long long sum = 0;
    vector<int> s1, t1;
    for (int i=0; i<n+m; i++){
        if (s[i] == '1'){
            s1.push_back(i);
        }
        if (t[i] == '1'){
            t1.push_back(i);
        }
    }
    for (int i=0; i<m; i++){
        sum += abs(s1[i]-t1[i]);
    }
    long long half = sum/2;
    cout << half*half + (sum-half)*(sum-half) << '\n';
}