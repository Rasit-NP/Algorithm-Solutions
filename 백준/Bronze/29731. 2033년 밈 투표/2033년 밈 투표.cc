# include <iostream>
# include <string>
# include <unordered_set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    unordered_set<string> data = {
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "Never gonna stop"
    };

    bool changed = false;
    
    int n;  cin >> n;
    cin.ignore();

    while (n--){
        string sent;    getline(cin, sent);
        if (data.find(sent) == data.end()){
            changed = true;
        }
    }

    if (changed){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}