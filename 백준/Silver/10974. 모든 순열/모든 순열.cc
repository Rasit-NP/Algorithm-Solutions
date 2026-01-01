# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

vector<int> list;
unordered_set<int> set;

void dfs(int n){
    if (list.size() == n){
        for (int i=0; i<n; i++){
            if (i)  cout << ' ';
            cout << list[i];
        }
        cout << '\n';
        return;
    }
    for (int i=1; i<=n; i++){
        if (set.find(i) == set.end()){
            list.push_back(i);
            set.insert(i);
            dfs(n);
            set.extract(i);
            list.pop_back();
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int n;  cin >> n;
    dfs(n);
}