# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, p;   cin >> n >> p;

    int discount[5] = {0, 500, p/10, 2000, p/4};
    int res = 0;
    for (int i=1; i<=min(4, n/5); i++){
        res = max(res, discount[i]);
    }

    cout << p - min(p, res);
}