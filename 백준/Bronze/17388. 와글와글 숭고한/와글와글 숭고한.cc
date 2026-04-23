# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int s, k, h;    cin >> s >> k >> h;
    if (s+k+h >= 100){
        cout << "OK";
    }
    else if (s < min(k, h)){
        cout << "Soongsil";
    }
    else if (k < min(s, h)){
        cout << "Korea";
    }
    else if (h < min(s, k)){
        cout << "Hanyang";
    }
}