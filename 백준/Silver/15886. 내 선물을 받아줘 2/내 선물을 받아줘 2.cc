# include <iostream>
# include <vector>
# include <string>
# include <queue>
using namespace std;

string word;
vector<int> visited;
int cnt = 0;

int dfs(int& x){
    if (visited[x] != -1)
        return visited[x];
    visited[x] = 0;
    int nx;
    if (word[x] == 'E'){
        nx = x+1;
    }
    else {
        nx = x-1;
    }
    if (visited[nx] == 0){
        visited[x] = ++cnt;
    }
    else {
        visited[x] = dfs(nx);
    }
    return visited[x];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;          cin >> n;
    cin >> word;
    visited.assign(n, -1);

    for (int i=0; i<n; i++){
        if (visited[i] == -1){
            visited[i] = dfs(i);
        }
    }

    cout << cnt;
}