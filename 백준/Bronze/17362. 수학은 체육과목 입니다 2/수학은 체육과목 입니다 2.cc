# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int a = n%8;
    if (a == 1){
        cout << 1;
    }
    else if (a == 2 || a == 0){
        cout << 2;
    }
    else if (a == 3 || a == 7){
        cout << 3;
    }
    else if (a == 4 || a == 6){
        cout << 4;
    }
    else {
        cout << 5;
    }
}