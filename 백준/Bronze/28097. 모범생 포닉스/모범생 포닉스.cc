# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int sum = 0;
    for (int i=0; i<n; i++){
        if (i)
            sum += 8;
        int t;  cin >> t;
        sum += t;
    }

    cout << sum/24 << ' ' << sum%24;
}