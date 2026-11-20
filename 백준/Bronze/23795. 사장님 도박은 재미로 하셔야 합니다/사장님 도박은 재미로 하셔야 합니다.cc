# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    int res = 0;
    
    while (true){
        int n;    cin >> n;
        if (n == -1)
            break;
        res += n;
    }
    
    cout << res << '\n';
}