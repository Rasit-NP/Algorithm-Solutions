# include <vector>
# include <queue>
using namespace std;
typedef long long ll;

bool isAble;
int sz;
vector<int> tree;
queue<int> q;

int dfs(int x){
    if (x >= sz){
        if (q.size()){
            tree[x] = q.front();    q.pop();    
        }
        else {
            tree[x] = 0;
        }
        return tree[x];
    }
    int res = 0;
    res = res | dfs(2*x+1);
    if (q.size()){
        tree[x] = q.front();    q.pop();    
    }
    else {
        tree[x] = 0;
    }
    res = res | dfs(2*x);
    
    if (res == 1 && tree[x] == 0){
        isAble = false;
    }
    return tree[x];
}

int solve(ll number){
    int len = 0;
    isAble = true;
    sz = 1;
    for (ll now=number; now; now >>= 1, ++len);
    while(sz*2-1 < len){
        sz <<= 1;
    }
    
    while (number){
        q.push(number & 1);
        number >>= 1;
    }
    
    tree.assign(sz*2, 0);
    
    dfs(1);
    
    return isAble;
}

vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    answer.reserve(10'000);
    
    for (ll number: numbers){
        int res = solve(number);
        answer.push_back(res);
    }
    
    return answer;
}