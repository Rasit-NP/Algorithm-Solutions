# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int s, d;   cin >> s >> d;
    int large, small;
    if ((s+d)&1){
        cout << -1;
        return 0;
    }
    large = (s+d)/2;
    small = s - large;

    if (small < 0){
        cout << -1;
    }
    else {
        cout << large << ' ' << small;
    }
}