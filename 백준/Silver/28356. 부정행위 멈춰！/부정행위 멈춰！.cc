# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> seats;

int getNum(int x, int y){
    vector<int> check(5, 0);
    int nx, ny;
    for (int dx : {-1, 0}){
        nx = x + dx;
        if (nx < 0 || nx >= n)
            continue;
        for (int dy : {-1, 0, 1}){
            if (dx == 0 && dy == 0)
                continue;
            ny = y + dy;
            if (ny < 0 || ny >= m)
                continue;
            check[seats[nx][ny]] = 1;
        }
    }
    for (int i=1; i<=4; i++){
        if (check[i] == 0){
            return i;
        }
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    seats.assign(n, vector<int>(m, 0));

    int res = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int num = getNum(i, j);
            seats[i][j] = num;
            res = max(res, num);
        }
    }

    cout << res << '\n';
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (j)
                cout << ' ';
            cout << seats[i][j];
        }
        cout << '\n';
    }
}