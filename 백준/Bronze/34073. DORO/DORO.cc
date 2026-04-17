# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    string word;
    for (int i=0; i<n; i++){
        cin >> word;
        if (i)
            cout << ' ';
        cout << word << "DORO";
    }
}