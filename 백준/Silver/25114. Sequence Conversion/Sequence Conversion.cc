# include <iostream>
# include <vector>
using namespace std;

int main(void){
    int n;  cin >> n;
    vector<int> a(n, 0), b(n, 0);

    for (int& num : a){
        cin >> num;
    }
    for (int& num : b){
        cin >> num;
    }

    int cnt = 0;

    for (int i=0; i<n-1; i++){
        int& ai = a[i], bi = b[i];
        if (ai == bi)
            continue;
        int diff = ai ^ bi;
        ai ^= diff;
        a[i+1] ^= diff;
        cnt++;
    }
    if (a.back() == b.back()){
        cout << cnt;
    }
    else {
        cout << -1;
    }
}