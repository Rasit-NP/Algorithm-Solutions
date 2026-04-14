# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    for (int tc=1; tc<=t; tc++){
        int a, b;   cin >> a >> b;
        cout << "Case " << tc << ": " << a+b << '\n';
    }
}