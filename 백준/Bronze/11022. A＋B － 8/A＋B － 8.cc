# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, a, b;
    cin >> t;
    for (int tc=1; tc<=t; tc++){
        cout << "Case #" << tc << ": ";
        cin >> a >> b;
        cout << a << " + " << b << " = ";
        cout << a+b << '\n';
    }
}