# include <iostream>
using namespace std;

int main(void){
    int a, b, c, d;    cin >> a >> b >> c >> d;
    if (a+c < b+d)
        cout << "Hanyang Univ.";
    else if (a+c == b+d)
        cout << "Either";
    else
        cout << "Yongdap";
}