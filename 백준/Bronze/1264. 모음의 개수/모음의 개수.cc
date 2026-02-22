# include <iostream>
# include <string>
# include <unordered_set>
using namespace std;

int main(void){
    string sent;
    unordered_set<char> mom = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    while(true){
        getline(cin, sent);
        int cnt = 0;
        if (sent == "#")
            break;
        for (char let : sent){
            if (mom.find(let) != mom.end()){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}