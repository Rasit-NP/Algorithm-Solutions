# include <vector>
using namespace std;

int res;
int len;
int a, b;
int N, M;
vector<vector<vector<int>>> visited;
vector<vector<int>> info;

void backtrack(int idx){
    if (idx == len){
        res = min(res, a);
        return;
    }
    
    if (visited[idx][a][b]){
        return;
    }

    int val = info[idx][0];
    a += val;
    if (a < N && a <= res){
        backtrack(idx+1);
    }
    a -= val;
    
    val = info[idx][1];
    b += val;
    if (b < M){
        backtrack(idx+1);
    }
    b -= val;
    
    visited[idx][a][b] = 1;
}

int solution(vector<vector<int>> data, int n, int m) {
    info = data;
    res = 121;
    len = data.size();
    
    a = 0, b = 0;
    N = n, M = m;
    
    visited.assign(len, vector<vector<int>>(n, vector<int>(m, 0)));
    backtrack(0);
    
    if (res >= n){
        return -1;
    }
    else {
        return res;
    }
}