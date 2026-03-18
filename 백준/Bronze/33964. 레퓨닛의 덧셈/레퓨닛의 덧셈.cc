# include <iostream>
# include <string>
using namespace std;

int main(void){
    int a, b;    cin >> a >> b;
    string x, y;
    x.assign(a, '1');
    y.assign(b, '1');
    cout << stoi(x) + stoi(y);
}