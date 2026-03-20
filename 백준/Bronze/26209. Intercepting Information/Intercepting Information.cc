# include <iostream>
using namespace std;

int main(void){
    int x;
    bool chk = true;
    while (cin >> x){
        if (x == 9)
            chk = false;
    }
    cout << (chk ? "S" : "F");
}