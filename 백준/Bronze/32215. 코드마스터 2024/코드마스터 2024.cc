# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m, k;    cin >> n >> m >> k;
    cout << (k+1)*m;
}