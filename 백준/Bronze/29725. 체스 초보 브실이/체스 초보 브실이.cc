# include <iostream>
# include <map>
using namespace std;

map<char, int> scoreBoard = {{'K', 0}, {'P', 1}, {'N', 3}, {'B', 3}, {'R', 5}, {'Q', 9}};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int big = 0, small = 0;
    
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            char data;  cin >> data;
            if (data == '.'){
                continue;
            }
            else if (data < 'a'){
                big += scoreBoard[data];
            }
            else {
                small += scoreBoard[data ^ (1<<5)];
            }
        }
    }

    cout << big - small;
}