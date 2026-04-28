# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int res = 0;
    for (int i=0; i<5; i++){
        int x;  cin >> x;
        if (x == n){
            ++res;
        }
    }

    cout << res;
}