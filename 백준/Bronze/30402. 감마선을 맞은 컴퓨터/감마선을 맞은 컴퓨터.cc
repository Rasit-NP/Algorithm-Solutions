# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string ans;

    for (int i=0; i<225; i++){
        char let;   cin >> let;
        if (let == 'w'){
            ans = "chunbae";
        }
        else if (let == 'b'){
            ans = "nabi";
        }
        else if (let == 'g'){
            ans = "yeongcheol";
        }
    }

    cout << ans;
}