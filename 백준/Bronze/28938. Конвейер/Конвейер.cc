# include <iostream>
using namespace std;


int main(void){
    int n;  cin >> n;
    int res = 0;
    while (n--){
        int x;  cin >> x;
        res += x;
    }

    cout << (res > 0 ? "Right" : (res < 0 ? "Left" : "Stay"));
}