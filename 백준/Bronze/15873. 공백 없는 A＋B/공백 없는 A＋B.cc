# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string word;    cin >> word;
    if (word.size() == 2){
        cout << (int)word[0] + (int)word[1] - '0'*2;
    }
    else if (word.size() == 3){
        if (word[1] == '0'){
            cout << 10 + word[2] - '0';
        }
        else {
            cout << 10 + word[0] - '0';
        }
    }
    else {
        cout << 20;
    }
}