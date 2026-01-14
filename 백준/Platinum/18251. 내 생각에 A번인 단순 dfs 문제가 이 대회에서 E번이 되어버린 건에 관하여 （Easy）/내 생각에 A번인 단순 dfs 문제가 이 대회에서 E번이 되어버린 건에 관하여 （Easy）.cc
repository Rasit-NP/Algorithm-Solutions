# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;

int n;
vector<int> tree;
vector<long long> range;

void init(void){
    cin >> n;
    tree.assign(n+1, 0);
    for (int i=1; i<=n; i++){
        cin >> tree[i];
    }
}

void dfs(int node, int min_node, int max_node){
    if (2*node > n){
        if (node >= min_node && node <= max_node){
            range.push_back(tree[node]);
        }
        return;
    }
    dfs(2*node, min_node, max_node);
    if (node >= min_node && node <= max_node){
        range.push_back(tree[node]);
    }
    dfs(2*node+1, min_node, max_node);
}

long long cal_max(void){
    vector<long long> range_sum = {range[0]};
    long long max_sum = range[0];
    for (int i=1; i<range.size(); i++){
        if (range_sum[i-1] + range[i] <= range[i]){
            range_sum.push_back(range[i]);
        }
        else {
            range_sum.push_back(range_sum[i-1]+range[i]);
        }
        max_sum = max(max_sum, range_sum[i]);
    }
    return max_sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    init();
    long long maximum = -1<<30;
    for (int i=1; i<n+1; i *= 2){
        for (int j=2*i-1; j<n+1; j = 2*j + 1){
            range.clear();
            dfs(1, i, j);
            maximum = max(maximum, cal_max());
        }
    }
    cout << maximum << '\n';
}