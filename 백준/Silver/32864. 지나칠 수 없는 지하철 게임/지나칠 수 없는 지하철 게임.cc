# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<int> list(n);
    vector<bool> winner(n, false);

    for (int& num : list){
        cin >> num;
    }

    winner[n-1] = true;
    for (int i=n-1; i>0; i--){
        if (list[i] == 1 && winner[i] == true){
            if (list[i-1] == 1)
                winner[i-1] = false;
            else
                winner[i-1] = true;
        }
        else if (list[i] == 1 && winner[i] == false){
            winner[i-1] = true;
        }
        else if (list[i] == 0 && winner[i] == true){
            if (list[i-1] == 1)
                winner[i-1] = false;
            else
                winner[i-1] = true;
        }
        else if (list[i] == 0 && winner[i] == false){
            winner[i-1] = true;
        }
    }

    if (winner[1])
        cout << "mnx";
    else
        cout << "alsdkffhgk";
}