# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<int> odd, even;
    for (int i=1; i<=n; i++){
        int x, y;   cin >> x >> y;
        if ((x+y)&1){
            odd.push_back(i);
        }
        else {
            even.push_back(i);
        }
    }

    if (odd.size() == 0 || even.size() == 0){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for (int i=0; i<odd.size(); i++){
        if (i)
            cout << ' ';
        cout << odd[i];
    }
    for (int& num : even){
        cout << ' ' << num;
    }
}