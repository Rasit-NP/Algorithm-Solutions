# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int x, y, z;    cin >> x >> y >> z;
    int u, v, w;    cin >> u >> v >> w;

    cout << (u/100)*x + (v/50)*y + (w/20)*z;
}