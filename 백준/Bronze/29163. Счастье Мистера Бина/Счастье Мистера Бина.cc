# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    int n;    cin >> n;
    int odd = 0, even = 0;
    while (n--){
        int x;    cin >> x;
        if (x&1){
            odd++;
        }
        else{
            even++;
        }
    }
    cout << (even > odd ? "Happy" : "Sad");
}