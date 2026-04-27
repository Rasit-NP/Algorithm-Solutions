# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b;   cin >> a >> b;

    if (a < 100){
        cout << 1;
        return 0;
    }

    if (10000 > a*(100-b)){
        cout << 1;
    }
    else {
        cout << 0;
    }
}