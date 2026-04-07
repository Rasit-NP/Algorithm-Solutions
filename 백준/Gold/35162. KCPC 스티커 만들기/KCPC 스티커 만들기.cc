# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int k, c, p;    cin >> k >> c >> p;
        if (k == 0){
            if (c == 0 && p >= 2){
                cout << "Y\n";
            }
            else if (c == 1 && p>0){
                cout << "Y\n";
            }
            else if (c >= 2){
                cout << "Y\n";
            }
            else {
                cout << "N\n";
            }
        }
        else if (k == 1){
            if (c == 0 && p >= 2){
                cout << "Y\n";
            }
            else if (c >= 1){
                cout << "Y\n";
            }
            else {
                cout << "N\n";
            }
        }
        else if (k == 2){
            if (c == 0 && p >= 2){
                cout << "Y\n";
            }
            else if (c == 1 && p >= 1){
                cout << "Y\n";
            }
            else if (c >= 2){
                cout << "Y\n";
            }
            else {
                cout << "N\n";
            }
        }
        else if (k == 3){
            if (c == 0 && p >= 2){
                cout << "Y\n";
            }
            else if (c == 1 && p >= 1){
                cout << "Y\n";
            }
            else if (c >= 2){
                cout << "Y\n";
            }
            else {
                cout << "N\n";
            }
        }
    }
}