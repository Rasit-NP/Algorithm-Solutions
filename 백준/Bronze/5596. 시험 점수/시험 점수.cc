# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int s = 0, t = 0;
    for (int i=0; i<4; i++){
        int x;  cin >> x;
        s += x;
    }
    for (int i=0; i<4; i++){
        int x;  cin >> x;
        t += x;
    }

    cout << (s >= t ? s : t);
}