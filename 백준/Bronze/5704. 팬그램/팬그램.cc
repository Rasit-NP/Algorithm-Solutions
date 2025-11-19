# include <iostream>
# include <string>
# include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true){
        bool ans = true;
        int i;
        vector<bool> check(26, false);
        string line;
        getline(cin, line);
        if (line == "*")    break;
        for (int i=0; i<line.length(); i++){
            if (line[i] == ' ') continue;
            int num = line[i] - 'a';
            check[num] = true;
        }
        for (i=0; i<26; i++){
            if (!check[i]) {
                ans = false;
                break;
            }
        }
        if (ans)    cout << 'Y' << '\n';
        else        cout << 'N' << '\n';
    }
}