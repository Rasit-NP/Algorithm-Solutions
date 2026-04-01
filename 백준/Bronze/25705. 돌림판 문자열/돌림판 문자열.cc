# include <iostream>
# include <vector>
# include <string>
# include <unordered_set>
using namespace std;

bool check(string& word, string& target){
    unordered_set<char> sets;
    for (char& c : word){
        sets.insert(c);
    }
    bool res = true;
    for (char & c : target){
        if (sets.find(c) == sets.end()){
            res = false;
            break;
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    string word;    cin >> word;
    int m;  cin >> m;
    string target; cin >> target;

    if (!check(word, target)){
        cout << -1;
        return 0;
    }

    int wIdx = n-1;
    int idx = 0;
    int ans = 0;
    while (idx < m){
        wIdx++;
        wIdx %= n;
        ans++;

        if (word[wIdx] == target[idx]){
            idx++;
        }
    }
    cout << ans;
    
    return 0;
}