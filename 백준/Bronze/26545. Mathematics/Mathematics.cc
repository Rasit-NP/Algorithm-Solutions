# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    int n;    cin >> n;
    int res = 0;
    while (n--){
        int x;    cin >> x;
        res += x;
    }
    cout << res;
}