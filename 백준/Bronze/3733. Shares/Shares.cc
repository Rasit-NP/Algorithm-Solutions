# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    int x, s;
    while (cin >> x >> s){
        cout << s/(x+1) << '\n';
    }
}