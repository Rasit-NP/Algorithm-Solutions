# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int now = 1;
    for (int i=0; i<n; i++){
        int a, b;   cin >> a >> b;
        now += b-a;
        if (a*b & (1<<31)){
            now -= 1 * (b & (1<<31) ? -1 : 1);
        }
    }
    cout << (now>0 ? now : now-1);
}