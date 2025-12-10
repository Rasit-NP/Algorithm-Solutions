# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string semina, ans;
    int maximum = 0;
    int count;
    while (cin >> semina){
        cin >> count;
        if (count > maximum){
            ans = semina;
            maximum = count;
        }
    }
    cout << ans << '\n';
}