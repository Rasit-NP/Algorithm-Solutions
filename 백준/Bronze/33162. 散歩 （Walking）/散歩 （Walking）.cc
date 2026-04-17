# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int x;  cin >> x;

    if (x&1){
        cout << (x-1)/2 + 3;
    }
    else {
        cout << x/2;
    }
}