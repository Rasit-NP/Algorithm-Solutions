# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    int n;  cin >> n;
    vector<int> straws(n, 0);
    for (int& straw : straws){
        cin >> straw;
    }

    sort(straws.begin(), straws.end());

    int ans = -1;
    for (int i=n-3; i>=0; i--){
        if (straws[i] + straws[i+1] > straws[i+2]){
            ans = straws[i] + straws[i+1] + straws[i+2];
            break;
        }
    }

    cout << ans;
}