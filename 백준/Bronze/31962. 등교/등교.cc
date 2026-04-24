# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, x;   cin >> n >> x;
    int ans = 0;
    for (int i=0; i<n; i++){
        int s, t;   cin >> s >> t;
        if (s + t <= x){
            ans = (ans < s ? s : ans);
        }
    }

    cout << (ans ? ans : -1);
}