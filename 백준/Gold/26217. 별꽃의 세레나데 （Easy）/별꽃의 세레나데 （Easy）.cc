# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    double res=0;
    for (int i=1; i<=n; i++){
        res += (double)1/i;
    }
    res *= n;
    cout << res << '\n';
}