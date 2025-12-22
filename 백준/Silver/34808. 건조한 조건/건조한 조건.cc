# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;    cin >> n >> m >> k;
    if (n != 1 && m != 1){
        cout << "-1\n";
    }
    else if (n*m == 2 && k == 0){
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (j)  cout << ' ';
                cout << 0;
            }
            cout << '\n';
        }
    }
    else if (k == 0){
        cout << "-1\n";
    }
    else {
        long long now = 0;
        if (n == 1){
            for (int i = 0; i<m; i++){
                if (i)  cout << ' ';
                cout << now;
                now += k;
            }
        }
        else if (m == 1){
            for (int i = 0; i<n; i++){
                if (i)  cout << '\n';
                cout << now;
                now += k;
            }
        }
        cout << '\n';
    }
}