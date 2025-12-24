# include <iostream>

using namespace std;

int main(void){
    long long h, s; cin >> h >> s;

    if (h <= 2){
        cout << "1\n";
        return 0;
    }
    if (h <= 4){
        cout << (h+1)/2 + s << '\n';
        return 0;
    }
    cout << (h + s*3 + 1)/2 << '\n';
}