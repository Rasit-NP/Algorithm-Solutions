# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int t;  cin >> t;

    while (t--){
        string word;    cin >> word;

        bool direc[4] = {false, false, false, false};
        
        for (char let : word){
            if (let == 'E'){
                direc[0] = true;
            }
            else if (let == 'W'){
                direc[1] = true;
            }
            else if (let == 'S'){
                direc[2] = true;
            }
            else {
                direc[3] = true;
            }
        }

        if (direc[0] == direc[1] && direc[2] == direc[3]){
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}