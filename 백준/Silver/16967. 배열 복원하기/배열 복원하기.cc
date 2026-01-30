# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int h, w, x, y; cin >> h >> w >> x >> y;
    vector<vector<int>> B(h+x, vector<int>(w+y, 0));
    vector<vector<int>> A(h, vector<int>(w, 0));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i=0; i<h+x; i++){
        for (int j=0; j<w+y; j++){
            cin >> B[i][j];
        }
    }
    for (int i=0; i<h+x; i++){
        for (int j=0; j<w+y; j++){
            if ((i>=h || j>=w) && i>=x && j>=y){
                A[i-x][j-y] = B[i][j];
                visited[i-x][j-y] = true;
            }
            else if ((i<x || j<y) && i<h && j<w){
                A[i][j] = B[i][j];
                visited[i][j] = true;
            }
        }
    }
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (visited[i][j] && i+x<h && j+y<w){
                visited[i+x][j+y] = true;
                A[i+x][j+y] = B[i+x][j+y] - A[i][j];
            }
        }
    }
    for (vector<int> row : A){
        for (int v : row){
            cout << v << ' ';
        }
        cout << endl;
    }
}