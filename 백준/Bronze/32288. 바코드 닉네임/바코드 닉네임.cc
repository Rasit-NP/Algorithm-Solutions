# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    char letter;
    for (int i=0; i<n; i++){
        cin >> letter;
        if (letter >= 97){
            cout << (char)(letter - 32);
        }
        else {
            cout << (char)(letter + 32);
        }
    }
    cout << '\n';
}