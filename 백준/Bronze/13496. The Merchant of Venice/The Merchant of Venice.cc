# include <iostream>
using namespace std;

void solve(const int& tc){
    cout << "Data Set " << tc << ":\n";

    int n, s, d;    cin >> n >> s >> d;
    int sum = 0;
    for (int i=0; i<n; i++){
        int di, v;  cin >> di >> v;
        if (s*d >= di){
            sum += v;
        }
    }

    cout << sum << "\n\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    for (int tc=1; tc<=t; tc++){
        solve(tc);
    }
}