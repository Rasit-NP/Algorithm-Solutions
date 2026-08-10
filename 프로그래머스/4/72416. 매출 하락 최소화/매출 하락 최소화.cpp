# include <vector>
# include <climits>
# include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long llong;

int n;
vector<vector<int>> edges;
vector<int> salary;

void init(vector<int>&, vector<vector<int>>&);
pii dfs(int x){
    if (!edges[x].size()){
        return {0, salary[x]};
    }
    
    int diff = INT_MAX;
    int minSal = INT_MAX;
    llong total = 0;
    for (int nx : edges[x]){
        auto [a, b] = dfs(nx);
        total += a;
        if (diff <= 0 && b <= a){
            diff += b-a;
        }
        else {
            diff = min(diff, b-a);
        }
    }
    
    return {total + diff, total + salary[x] + min(0, diff)};
}

int solution(vector<int> sales, vector<vector<int>> links) {
    init(sales, links);
    
    const auto [a, b] = dfs(1);
    
    return min(a, b);
}

void init(vector<int>& sales, vector<vector<int>>& links){
    n = sales.size();
    edges.assign(n+1, vector<int>(0));
    salary.reserve(n+1);
    salary.emplace_back(0);
    
    for (int sale : sales){
        salary.emplace_back(sale);
    }
    
    for (vector<int>& link : links){
        int a = link[0], b = link[1];
        edges[a].emplace_back(b);
    }
}