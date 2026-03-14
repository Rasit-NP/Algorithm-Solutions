# include <iostream>
using namespace std;

int main(void){
    int total = 300;
    for (int i=0; i<4; i++){
        int x;    cin >> x;
        total += x;
    }
    cout << (total <= 1800 ? "Yes" : "No");
}