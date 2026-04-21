# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b;   cin >> a >> b;
    int c;  cin >> c;

    cout << (a+b >= 2*c ? a+b-2*c : a+b);
}