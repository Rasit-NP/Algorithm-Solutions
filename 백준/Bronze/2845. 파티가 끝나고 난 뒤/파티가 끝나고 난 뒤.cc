# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int l, p;   cin >> l >> p;
    int cmp = l*p;
    for (int i=0; i<5; i++){
        int x;  cin >> x;
        cout << x - cmp << " \n"[i==4];
    }
}