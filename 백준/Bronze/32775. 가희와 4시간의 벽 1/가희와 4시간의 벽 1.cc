# include <iostream>
using namespace std;

int main(void){
    int s, f;   cin >> s >> f;
    if (s <= f)
        cout << "high speed rail";
    else
        cout << "flight";
}