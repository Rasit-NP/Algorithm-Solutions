# include <iostream>
using namespace std;

int main(void){
    while(true){
        int a, b;    cin >> a >> b;
        if (a+b){
            cout << (a>b ? "Yes\n" : "No\n");
        }
        else
            break;
    }
}