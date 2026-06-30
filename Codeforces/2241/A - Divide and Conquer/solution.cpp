# include <iostream>
# include <vector>
using namespace std;
 
vector<vector<int>> table;
 
bool get(int x, int y){
    if (x == y){
        table[x][y] = 1;
        return true;
    }
    if (table[x][y] != -1){
        return table[x][y];
    }
 
    bool res = false;
 
    for (int z=2; z<=x; z++){
        if (x%z == 0){
            table[x][x/z] = 1;
            if (get(x/z, y)){
                res = true;
                break;
            }
        }
    }
 
    table[x][y] = res;
 
    return res;
}
 
void solve(){
    int x, y;   cin >> x >> y;
 
    if (get(x, y)){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    table.assign(101, vector<int>(101, -1));
 
    while (t--){
        solve();
    }
}