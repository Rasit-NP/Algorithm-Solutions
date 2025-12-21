# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, s; cin >> t >> s;
    if ((t>=12 && t<=16) && !s){
        cout << "320\n";
    }
    else {
        cout << "280\n";
    }
}