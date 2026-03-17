# include <iostream>
# include <string>
using namespace std;

int main(void){
    string n;    cin >> n;
    bool check = false;
    for (char x : n){
        if (x == '7')
            check = true;
    }
    if (check){
        if (stoi(n)%7)
            cout << 2;
        else
            cout << 3;
    }
    else {
        if (stoi(n)%7)
            cout << 0;
        else
            cout << 1;
    }
}