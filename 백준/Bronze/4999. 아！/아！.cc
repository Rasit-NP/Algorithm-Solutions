# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string ah1, ah2;    cin >> ah1 >> ah2;
    if (ah1.length() < ah2.length())
        cout << "no\n";
    else
        cout << "go\n";
}