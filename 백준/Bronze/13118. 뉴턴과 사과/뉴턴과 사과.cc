# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int p[5];
    for (int i=1; i<=4; i++){
        cin >> p[i];
    }
    int x, y, r;    cin >> x >> y >> r;

    for (int i=1; i<5; i++){
        if (p[i] == x){
            cout << i;
            return 0;
        }
    }

    cout << 0;
}