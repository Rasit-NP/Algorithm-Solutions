# include <iostream>
# include <vector>
# include <queue>
using namespace std;

struct Fruits{
    int apple;
    int pear;

    Fruits(){
        apple = 0;
        pear = 0;
    }

    Fruits(int x): Fruits(){
        if (x == 1){
            this->apple = 1;
        }
        else if (x == 2){
            this->pear = 1;
        }
    }

    Fruits operator+(Fruits& fruit){
        Fruits newFruit = Fruits();
        newFruit.apple = this->apple + fruit.apple;
        newFruit.pear = this->pear + fruit.pear;
        return newFruit;
    }

    bool operator<(const Fruits& fruit) const {
        int thisMult = this->apple * this->pear;
        int cmpMult = fruit.apple * fruit.pear;
        if (thisMult < cmpMult){
            return true;
        }
        else if (thisMult == cmpMult) {
            if (this->apple < fruit.apple){
                return true;
            }
            else if (this->apple == fruit.apple){
                return this->pear < fruit.pear;
            }
        }
        return false;
    }
};

int n, k, MAX;
vector<vector<int>> edges;
vector<vector<Fruits>> dp;
vector<Fruits> nodes;

int count(int state){
    int res = 0;
    while (state){
        res += state&1;
        state >>= 1;
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> k;
    MAX = 1 << n;
    edges.assign(n, vector<int>(0));
    dp.assign(n, vector<Fruits>(MAX));
    

    for (int i=0; i<n-1; i++){
        int p, c;   cin >> p >> c;
        edges[p].push_back(c);
        edges[c].push_back(p);
    }

    for (int i=0; i<n; i++){
        int x;  cin >> x;
        nodes.push_back(Fruits(x));
    }

    queue<pair<int, int>> q;
    dp[0][1] = nodes[0];
    q.push({0, 1});

    while (q.size()){
        auto [x, state] = q.front();   q.pop();
        for (int& nx : edges[x]){
            if ((state & (1 << nx)) && (dp[nx][state] < dp[x][state])){
                dp[nx][state] = dp[x][state];
                q.push({nx, state});
            }
            else if (!(state & (1 << nx))){
                int nState = state + (1 << nx);
                if (dp[nx][nState] < dp[x][state] + nodes[nx]){
                    dp[nx][nState] = dp[x][state] + nodes[nx];
                    q.push({nx, nState});
                }
            }
        }
    }

    Fruits ans;

    for (auto& row : dp){
        for (int state = 0; state < (1<<n); state++){
            if (count(state) <= k && ans < row[state]){
                ans = row[state];
            }
        }
    }

    cout << ans.apple << ' ' << ans.pear;

}