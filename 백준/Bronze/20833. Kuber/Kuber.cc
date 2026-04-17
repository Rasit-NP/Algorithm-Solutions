# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int res = 0;
    for (int i=1; i<=n; i++){
        res += i*i*i;
    }

    cout << res;
}