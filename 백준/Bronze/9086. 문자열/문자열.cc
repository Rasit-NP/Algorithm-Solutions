# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc=0; tc<t; tc++){
        string word;
        cin >> word;
        cout << word[0] << word[word.length()-1] << endl;
    }
}