# include <vector>
# include <algorithm>
using namespace std;

int n, k;
int res, now;
vector<int> cnt;
vector<vector<int>> cost;
vector<vector<int>> hint;

void f(int x){
    if (x == n){
        res = min(now, res);
        return;
    }
    int c = cost[x][cnt[x]];
    
    now += c;
    for (int i=0; i<2; i++){
        if (i && x < n-1){
            int hintCost = hint[x][0];
            vector<int> tmp = cnt;
            for (int i=1; i<=k; i++){
                int nx = hint[x][i] - 1;
                cnt[nx] = min(cnt[nx] + 1, n-1);
            }
            now += hintCost;
            f(x+1);
            now -= hintCost;
            cnt = tmp;
        }
        else {
            f(x+1);
        }
    }
    now -= c;
}

int solution(vector<vector<int>> c, vector<vector<int>> h) {
    cost = c;
    hint = h;
    
    n = cost.size();
    k = hint[0].size() - 1;
    
    cnt.assign(n, 0);
    
    now = 0;
    res = 2'000'000;

    f(0);
    
    return res;
}