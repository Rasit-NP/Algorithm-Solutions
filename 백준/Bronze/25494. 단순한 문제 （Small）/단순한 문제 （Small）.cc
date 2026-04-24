# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    
    while (t--){
        int a, b, c;    cin >> a >> b >> c;
        int ans = 0;
        for (int i=1; i<=a; i++){
            for (int j=1; j<=b; j++){
                for (int k=1; k<=c; k++){
                    if ((i%j == j%k) && (j%k == k%i) && (k%i == j%k)){
                        ++ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}