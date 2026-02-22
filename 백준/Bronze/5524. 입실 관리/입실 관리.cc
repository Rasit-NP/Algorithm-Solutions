# include <iostream>
# include <string>
using namespace std;

int main(void){
    int n;  cin >> n;
    while(n--){
        string word;    cin >> word;
        for (char &let : word){
            if (let < 97){
                let |= 1<<5;
            }
        }
        cout << word << endl;
    }
}