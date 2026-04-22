# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;
    long long s;
    cin >> n >> m >> s;

    long long ans = 0;
    if (n*(m+1) > 100){
        ans = s*(m+1)*(100-n)/100;
    }
    else {
        ans = s*m;
    }

    cout << ans;
}