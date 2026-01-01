# include <iostream>
# include <string>
# include <unordered_set>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    unordered_set<string> set;
    string word;
    for (int i=0; i<n; i++){
        cin >> word;
        sort(word.begin(), word.end());
        set.insert(word);
    }
    cout << set.size() << '\n';
}