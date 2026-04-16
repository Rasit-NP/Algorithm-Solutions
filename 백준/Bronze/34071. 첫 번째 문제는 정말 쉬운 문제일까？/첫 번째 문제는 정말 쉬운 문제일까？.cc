# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int mini = 1001, maxi = 0;
    vector<int> difficulties;
    difficulties.reserve(n);
    while (n--){
        int x;  cin >> x;
        mini = min(mini, x);
        maxi = max(maxi, x);
        difficulties.emplace_back(x);
    }

    if (difficulties[0] == mini){
        cout << "ez";
    }
    else if (difficulties[0] == maxi){
        cout << "hard";
    }
    else {
        cout << "?";
    }
}