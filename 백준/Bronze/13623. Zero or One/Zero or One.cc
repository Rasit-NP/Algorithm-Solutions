# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b, c;    cin >> a >> b >> c;

    if (a == b && b == c){
        cout << '*';
    }
    else if (a == b){
        cout << 'C';
    }
    else if (b == c){
        cout << 'A';
    }
    else{
        cout << 'B';
    }
}