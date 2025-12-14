# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> sums(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
            sums[i][j] = board[i][j];
            if (i > 0)  sums[i][j] += sums[i-1][j];
            if (j > 0)  sums[i][j] += sums[i][j-1];
            if (i > 0 && j > 0) sums[i][j] -= sums[i-1][j-1];
        }
    }
    int maximum = - 1<<30;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int size = 0; size < n-max(i, j); size++){
                int res=0;
                res += sums[i+size][j+size];
                if (i > 0)  res -= sums[i-1][j+size];
                if (j > 0)  res -= sums[i+size][j-1];
                if (i > 0 && j > 0) res += sums[i-1][j-1];
                maximum = max(maximum, res);
            }
        }
    }
    cout << maximum << '\n';
}