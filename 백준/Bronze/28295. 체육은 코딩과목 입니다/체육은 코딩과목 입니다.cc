# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    char directions[4] = {'N', 'E', 'S', 'W'};
    int now = 0;

    for (int i=0; i<10; i++){
        int t;  cin >> t;

        if (t==1){
            now += 1;
        }
        else if (t == 2){
            now += 2;
        }
        else {
            now += 3;         
        }

    }
    cout << directions[now%4];
}