# include <iostream>
# include <vector>
using namespace std;

int main(void){
    int n, d, i=0, j;
    cin >> n >> d;
    vector<vector<int>> board(n, vector<int>(n));
    for (; i<n; i++){
        for (j=0; j<n; j++){
            int x;
            cin >> x;
            if (x){
                board[i][j] += 1<<20;
                for (int di=-d; di<=d; di++){
                    for (int dj=-d; dj<=d; dj++){
                        int ni = i+di, nj = j+dj;
                        if (ni<0 || ni>=n || nj<0 || nj>=n)
                            continue;
                        board[ni][nj] += 1;
                    }
                }
            }
        }
    }
    pair<int, int> ans;
    int min = 1<<30;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (board[i][j] < min){
                ans.first = i+1, ans.second = j+1;
                min = board[i][j];
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
    if (min)
        cout << min;
}