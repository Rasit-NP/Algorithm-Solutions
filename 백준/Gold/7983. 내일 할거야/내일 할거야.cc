# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int n;  cin >> n;
    vector<pair<int, int>> datas;
    for (int i=0; i<n; i++){
        int d, t;   cin >> d >> t;
        datas.push_back(make_pair(-t, d));
    }
    sort(datas.begin(), datas.end());
    int maxi = 1 << 30;
    for (pair<int, int> data : datas){
        int t = -data.first, d = data.second;
        if (maxi < t){
            maxi -= d;
        }
        else {
            maxi = t-d;
        }
    }
    cout << maxi << '\n';
}