# include <iostream>
# include <string>
# include <set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    string word;    cin >> word;
    set<char> sets;
    for (char let : word){
        sets.insert(let);
    }
    string find = "MOBIS";


    for (char let : find){
        if (sets.find(let) == sets.end()){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}