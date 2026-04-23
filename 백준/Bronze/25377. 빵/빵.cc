# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    bool res = false;
    int n;  cin >> n;
    int ans = 1001;
    for (int i=0; i<n; i++){
        int a, b;   cin >> a >> b;
        if (a<=b){
            res = true;
            ans = min(ans, b);
        }
    }

    cout << (res ? ans : -1);
}