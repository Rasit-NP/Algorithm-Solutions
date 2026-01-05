# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int n;  cin >> n;
    n = 7*(n-1) + 8;
    cout << 2024+((n-1)/12) << ' ' << (n-1)%12 + 1;
}