# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    string sent;
    while (getline(cin, sent)){
        if (sent == "END")
            break;
        reverse(sent.begin(), sent.end());
        cout << sent << '\n';
    }
}