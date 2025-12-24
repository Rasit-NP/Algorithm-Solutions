# include <iostream>
# include <vector>
# include <queue>
# include <string>
using namespace std;

int main(void){
    int n, k;       cin >> n >> k;
    string board;   cin >> board;

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;
    while (q.size()){
        int x = q.front();
        q.pop();

        if (x == n-1){
            cout << "YES\n";
            return 0;
        }
        int nx = x+1;
        if (nx<n && !visited[nx] && board[nx] == '_'){
            visited[nx] = true;
            q.push(nx);
        }
        nx = x+k;
        if (nx<n && !visited[nx] && board[nx] == '_'){
            visited[nx] = true;
            q.push(nx);
        }
    }
    cout << "NO\n";
}