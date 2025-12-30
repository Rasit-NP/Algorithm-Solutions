# include <iostream>
# include <string>
# include <unordered_map>
# include <algorithm>
using namespace std;

string trans(string word){
    if (word.length() < 3)  return word;
    string middle = word.substr(1, word.length() - 2);
    sort(middle.begin(), middle.end());

    return word.front() + middle + word.back();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    string word;
    unordered_map<string, string> dict;
    for (int i=0; i<n; i++){
        cin >> word;
        dict[trans(word)] = word;
    }
    int m;  cin >> m;
    for (int i=0; i<m; i++){
        if (i)  cout << ' ';
        cin >> word;
        cout << dict[trans(word)];
    }
}