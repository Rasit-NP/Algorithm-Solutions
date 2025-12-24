# include <iostream>
# include <string>
# include <vector>
# include <unordered_set>
using namespace std;

int main(void){
    int n; cin >> n;
    string word; cin >> word;
    unordered_set <char> letters = {'P', 'A', 'U', 'L'};
    vector<char> ans;
    if (n & 1){
        cout << "NO\n";
        return 0;
    }
    for (int i=0; i<n;){
        char letter = word[i];
        if (letters.find(letter) == letters.end()){
            i += 2;
        }
        else {
            ans.push_back(letter);
            i += 1;
        }
    }
    if (ans.size() != 4){
        cout << "NO\n";
        return 0;
    }
    if (ans[0] == 'P' && ans[1] == 'A' && ans[2] == 'U' && ans[3] == 'L'){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}