# include <iostream>
using namespace std;

int main(void){
    int t;  cin >> t;
    while (t--){
        static int tc = 1;
        int a, b;   cin >> a >> b;

        cout << "Case #" << tc++ << ": " << a + b << '\n';
    }
}