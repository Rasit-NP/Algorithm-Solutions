# include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;  cin >> n;
    vector<int> solved = {12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6};
    vector<int> panelty = {1600, 894, 1327, 1311, 1004, 1178, 1357, 837, 1055, 556, 773};

    cout << solved[n-1] << ' ' << panelty[n-1] << '\n';
}