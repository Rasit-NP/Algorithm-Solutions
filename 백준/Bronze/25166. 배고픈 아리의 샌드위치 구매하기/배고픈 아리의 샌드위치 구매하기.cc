# include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int s, m;
    cin >> s >> m;
    if (s <= 1023)                      cout << "No thanks\n";
    else if (((s-1023)&m) == (s-1023))    cout << "Thanks\n";
    else                                cout << "Impossible\n";
}