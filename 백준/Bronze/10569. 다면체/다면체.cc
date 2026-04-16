# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int t;  cin >> t;
    while (t--){
        int v, e;   cin >> v >> e;
        cout << 2-v+e << '\n';
    }
}