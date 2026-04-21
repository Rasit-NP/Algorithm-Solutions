# include <iostream>
# include <string>
# include <unordered_set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string word;    cin >> word;
    int ans1 = 0, ans2 = 0;
    unordered_set<char> sets = {'a', 'e', 'i', 'o', 'u'};

    for (char& let : word){
        if (sets.find(let) != sets.end()){
            ans1++;
            ans2++;
        }
        else if (let == 'y'){
            ans2++;
        }
    }

    cout << ans1 << ' ' << ans2;
}