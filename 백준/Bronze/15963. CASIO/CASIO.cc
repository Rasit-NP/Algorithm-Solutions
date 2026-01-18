# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    long long n, m; cin >> n >> m;

    cout << (n == m) ? 1 : 0;
}