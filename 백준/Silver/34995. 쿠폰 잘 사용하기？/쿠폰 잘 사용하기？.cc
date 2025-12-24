# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;          cin >> n;
    string coupon;  cin >> coupon;
    string a;       cin >> a;
    if (n < a.length()){
        cout << "-1\n";
        return 0;
    }
    for (int i=0; i<n; i++){
        if (coupon[i] == '?'){
            coupon[i] = '9';
        }
    }
    if (n > a.length()){
        cout << coupon << '\n';
        return 0;
    }
    bool check = true;
    for (int i=0; i<n; i++){
        int left = stoi(a.substr(i, 1)), right = stoi(coupon.substr(i, 1));
        if (right > left){
            break;
        }
        else if (left > right){
            check = false;
            break;
        }
    }
    if (check){
        cout << coupon << '\n';
    }
    else {
        cout << "-1\n";
    }
}