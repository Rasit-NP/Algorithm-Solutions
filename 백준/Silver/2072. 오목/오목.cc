# include <iostream>
# include <vector>
using namespace std;

vector<pair<int, int>> dxdys = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

struct Board{
private:
    vector<vector<int>> board;

public:
    Board(void){
        board.assign(19, vector<int>(19));
    }

    vector<int>& operator[] (int x){
        return this->board[x];
    }

    void put(int& x, int& y, int type){
        this->board[x][y] = type;
    }

    bool check(int& x, int& y){
        int value = board[x][y];
        for (const auto& [dx, dy] : dxdys){
            int left = 0, right = 0;
            for (int t=1; t<6; t++){
                int nxr = x + dx*t, nyr = y + dy*t;
                if (nxr >= 19 || nxr < 0 || nyr >= 19 || nyr < 0 || board[nxr][nyr] != value){
                    break;
                }
                right = t;
            }
            for (int t=1; t<6; t++){
                int nxl = x - dx*t, nyl = y - dy*t;
                if (nxl >= 19 || nxl < 0 || nyl >= 19 || nyl < 0 || board[nxl][nyl] != value){
                    break;
                }
                left = t;
            }
            if (left + right == 4){
                return true;
            }
        }
        return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int ans = -1;
    Board board = Board();

    for (int i=1; i<=n; i++){
        int x, y;   cin >> x >> y;
        x--;    y--;
        board.put(x, y, (i&1 ? 1 : 2));
        if (board.check(x, y)){
            if (ans == -1)
                ans = i;
        }
    }
    cout << ans;
}