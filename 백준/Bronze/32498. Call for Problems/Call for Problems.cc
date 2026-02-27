# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int cnt = 0;
    while (n--){
        int v;  cin >> v;
        if (v&1)
            cnt++;
    }
    cout << cnt;
}