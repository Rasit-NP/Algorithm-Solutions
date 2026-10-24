# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int n, k;
int start;
vector<vector<int>> edges[4];
vector<int> orders;
int res = 0;

int getValue(){
    int now = 0;
    vector<int> visited(n+1, 0);
    visited[start] = 1;
    
    for (int type : orders){
        vector<vector<int>>& edge = edges[type];
        queue<int> q;
        
        for (int i=1; i<=n; ++i){
            if (visited[i] == 1)
                q.push(i);
        }
        
        while (q.size()){
            int x = q.front();  q.pop();
            
            for (int nx : edge[x]){
                if (visited[nx] == 0){
                    visited[nx] = 1;
                    q.push(nx);
                }
            }
        }
    }
    
    for (int i=1; i<=n; ++i){
        now += visited[i];
    }
    
    return now;
}

void getOrder(){
    if (orders.size() == k){
        res = max(res, getValue());
        return;
    }
    
    for (int i=1; i<=3; ++i){
        if (orders.size() && orders.back() == i)
            continue;
        
        orders.push_back(i);
        getOrder();
        orders.pop_back();
    }
}

int solution(int N, int infection, vector<vector<int>> es, int K) {
    n = N;
    k = K;
    start = infection;
    
    for (int i=1; i<=3; ++i){
        edges[i].assign(n+1, vector<int>(0));
    }
    
    for (vector<int>& e : es){
        int x = e[0], y = e[1];
        int type = e[2];
        
        edges[type][x].push_back(y);
        edges[type][y].push_back(x);
    }
    
    getOrder();
    
    return res;
}