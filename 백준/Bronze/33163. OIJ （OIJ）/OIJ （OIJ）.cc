# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    for (int i=0; i<n; i++){
        char let;   cin >> let;
        if (let == 'J'){
            cout << 'O';
        }
        else if (let == 'O'){
            cout << 'I';
        }
        else{
            cout << 'J';
        }
    }
}