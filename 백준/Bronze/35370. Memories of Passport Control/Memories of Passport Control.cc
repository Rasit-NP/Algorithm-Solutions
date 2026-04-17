# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int k, s;   cin >> k >> s;
    cout << s/k + s%k;
}