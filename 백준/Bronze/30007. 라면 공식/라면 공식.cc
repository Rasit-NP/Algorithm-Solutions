# include <iostream>
using namespace std;

int main(void){
    int n;  cin >> n;
    while (n--){
        int a, b, x;    cin >> a >> b >> x;
        cout << a * (x - 1) + b << endl;
    }
}