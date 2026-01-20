# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
using namespace std;

void run(void){
    int mini = INT_MAX;
    int sum = 0;
    for (int i=0; i<7; i++){
        int n;  cin >> n;
        if ((n&1) == 0){
            mini = min(mini, n);
            sum += n;
        }
    }
    cout << sum << ' ' << mini << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        run();
    }
}