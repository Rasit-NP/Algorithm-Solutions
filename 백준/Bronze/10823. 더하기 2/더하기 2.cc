# include <iostream>
# include <string>
using namespace std;

int main(void){
    string num;
    char c;
    int ans = 0;
    while (cin >> c){
        if (c == ','){
            ans += stoi(num);
            num.clear();
        }
        else {
            num.push_back(c);
        }
    }
    if (num.size()){
        ans += stoi(num);
        num.clear();
    }

    cout << ans;
}