# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    int n;  cin >> n;
    vector<int> weight(n, 0);
    for (int i=0; i<n; i++){
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
    long long sum=0;
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (sum <= weight[i]){
            sum += weight[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}