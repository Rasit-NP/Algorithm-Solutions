# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int x, y;   cin >> x >> y;
    if (y >= x){
        cout << y-x;
    }
    else {
        cout << y+x;
    }
}