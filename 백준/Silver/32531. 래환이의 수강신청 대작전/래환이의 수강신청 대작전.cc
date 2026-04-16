# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool compareVec(vector<int>& vec1, vector<int>& vec2){
    int sz = vec1.size();
    if (vec2.size() != sz){
        return false;
    }

    for (int i=0; i<sz; i++){
        if (vec1[i] != vec2[i]){
            return false;
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    int maxi = 0;
    vector<vector<int>> lists(m+1);
    vector<int> states(m+1);
    vector<int> countStates;

    for (int i=1; i<n; i++){
        int l, x;   cin >> l;
        while (l--){
            cin >> x;
            lists[x].push_back(i);
        }
    }

    for (int i=1; i<=m; i++){
        states[i] = i;
    }

    for (int i=1; i<=m; i++){
        for (int j=i+1; j<=m; j++){
            if (compareVec(lists[i], lists[j])){
                states[j] = states[i];
            }
        }
    }

    for (int i=1; i<=m; i++){
        maxi = max(maxi, states[i]);
    }

    countStates.assign(maxi+1, 0);


    for (int i=1; i<=m; i++){
        countStates[states[i]]++;
        if (countStates[states[i]] > 2){
            cout << 0;
            return 0;
        }
    }

    int ans = 1;

    for (int i=1; i<=maxi; i++){
        if (countStates[i] && lists[i].size()){
            ans *= 2;
        }
        else if (lists[i].size() == 0){
            if (countStates[i] > 1){
                cout << 0;
                return 0;
            }
        }
    }

    cout << ans;
}