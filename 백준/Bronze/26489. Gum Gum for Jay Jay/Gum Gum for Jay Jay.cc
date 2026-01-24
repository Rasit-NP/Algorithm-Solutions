# include <iostream>
# include <string>
using namespace std;

int main(void){
    int cnt = 0;
    string a;
    while (getline(cin, a)){
        cnt++;
    }
    cout << cnt << endl;
}