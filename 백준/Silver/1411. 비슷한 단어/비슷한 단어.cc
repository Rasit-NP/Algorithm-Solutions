# include <iostream>
# include <string>
# include <vector>
using namespace std;

int check(const string& a, const string& b){
    int res = 1;
    vector<char> transformer(26, '?');
    vector<char> reverse(26, '?');
    for (int i=0; i<a.size(); i++){
        char& result = transformer[a[i] - 'a'];
        char& result2 = reverse[b[i] - 'a'];

        if (result == '?' && result2 == '?'){
            result = b[i];
            result2 = a[i];
        }
        else if (result == b[i] && result2 == a[i]){
            continue;
        }
        else {
            res = 0;
            break;
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<string> words(n);
    int res = 0;

    for (string& word : words){
        cin >> word;
    }

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            res += check(words[i], words[j]);
        }
    }

    cout << res;
}