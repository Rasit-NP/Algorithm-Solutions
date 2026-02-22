# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    int n;  cin >> n;
    int ans = 0;
    vector<int> a(n, 0);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        int num;    cin >> num;
        ans += abs(num-a[i]);
    }
    cout << ans/2 << endl;
}