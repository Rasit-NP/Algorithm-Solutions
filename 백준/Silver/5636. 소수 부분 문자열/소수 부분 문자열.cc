# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string num;
    vector<bool> check(100001, true);
    check[0] = false; check[1] = false;
    for (int i=2; i<100001; i++){
        if (!check[i])  continue;
        for (int j=2*i; j<100001; j += i){
            check[j] = false;
        }
    }
    while (true){
        cin >> num;
        if (num == "0"){
            break;
        }
        int ans = 0;
        for (int i=5; i>0; i--){
            for (int j=0; j < num.length()-i; j++){
                int now = stoi(num.substr(j, i));
                if (check[now]) {
                    if (now>ans)
                        ans = now;
                }
            }
        }
        cout << ans << '\n';
    }
}