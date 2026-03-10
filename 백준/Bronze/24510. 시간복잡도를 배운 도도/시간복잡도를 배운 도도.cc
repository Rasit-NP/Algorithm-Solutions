# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int count(const string& word, const string& base){
    int len = base.length();
    if (word.length() < len){
        return 0;
    }
    int res = 0;

    for (int i=0; i<word.length() - len + 1; i++){
        if (word.substr(i, len) == base){
            res++;
        }
    }

    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int ans = 0;
    while (n--){
        string word;    cin >> word;
        ans = max(ans, count(word, "for") + count(word, "while"));
    }

    cout << ans;
}