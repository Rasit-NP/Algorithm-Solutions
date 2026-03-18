# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

int main(void){
    int n, m;       cin >> n >> m;
    string a, b;    cin >> a >> b;

    vector<int> data = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
    vector<int> res(0);

    for (int i=0; i<max(n, m); i++){
        if (i<n)
            res.push_back(data[a[i]-'A']);
        if (i<m)
            res.push_back(data[b[i]-'A']);
    }
    while (res.size() > 2){
        vector<int> tmp(res.size()-1, 0);
        for (int i=0; i<res.size()-1; i++){
            tmp[i] = (res[i] + res[i+1]) % 10;
        }
        res = tmp;
    }
    if (res[0]) cout << res[0];
    cout << res[1] << '%';
}