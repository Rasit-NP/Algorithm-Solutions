# include <iostream>
# include <vector>
typedef long long llong;
using namespace std;

int n, m;
vector<vector<llong>> board;
vector<vector<llong>> difference;
vector<vector<llong>> ans;
bool updateClear = false;

void summation();
void update();
void get();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    board.assign(n, vector<llong>(n));
    difference.assign(n+1, vector<llong>(n+1, 0));
    ans.assign(n+1, vector<llong>(n+1, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for (int i=0; i<m; i++){
        int order;  cin >> order;
        if (order == 1){
            summation();
        }
        else if (order == 2){
            if (!updateClear){
                update();
            }
            get();
        }
    }
}

void get(){
    int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
    llong res = ans[i2][j2];
    if (i1)
        res -= ans[i1-1][j2];
    if (j1)
        res -= ans[i2][j1-1];
    if (i1 && j1)
        res += ans[i1-1][j1-1];
    
    cout << res << '\n';
}

void update(){
    board[0][0] += difference[0][0];
    for (int i=1; i<n; i++){
        difference[i][0] += difference[i-1][0];
        difference[0][i] += difference[0][i-1];
        board[i][0] += difference[i][0];
        board[0][i] += difference[0][i];
    }
    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            difference[i][j] += difference[i-1][j] + difference[i][j-1] - difference[i-1][j-1];
            board[i][j] += difference[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ans[i][j] += board[i][j];
            if (i)
                ans[i][j] += ans[i-1][j];
            if (j)
                ans[i][j] += ans[i][j-1];
            if (i && j)
                ans[i][j] -= ans[i-1][j-1];
        }
    }
    updateClear = true;
}

void summation(){
    int i1, j1, i2, j2, k;  cin >> i1 >> j1 >> i2 >> j2 >> k;

    difference[i1][j1]      += k;
    difference[i2+1][j2+1]  += k;
    difference[i2+1][j1]    -= k;
    difference[i1][j2+1]    -= k;

}