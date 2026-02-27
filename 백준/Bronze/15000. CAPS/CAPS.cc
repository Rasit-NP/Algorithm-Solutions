# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string word;    cin >> word;
    for (char& letter : word){
        letter -= 1<<5;
    }
    cout << word;
}