# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    int n;  cin >> n;
    int sum = 0;
    for (int i=0; i<n; i++){
        int f;  cin >> f;
        sum += f;
    }
    if (sum >= t){
        cout << "Padaeng_i Happy";
    }
    else {
        cout << "Padaeng_i Cry";
    }
}