# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_set>
using namespace std;

int n;
vector<int> parents;
vector<vector<int>> edges;
vector<vector<int>> ans;

int find(int a){
    int x = a;
    while (parents[x] != x){
        x = parents[x];
        parents[x] = parents[parents[x]];
    }
    parents[a] = x;
    return x;
}

void run(int x){
    for (int nx = 0; nx < n; nx++){
        if (nx == x)
            continue;
        int fx = find(x), fnx = find(nx);
        if (edges[x][nx] == 0 && fx != fnx){
            parents[max(fx, fnx)] = min(fx, fnx);
        }
    }
}

bool check(int x){
    bool res = true;
    for (int nx = 0; nx < n; nx++){
        if (nx == x)
            continue;
        int fx = find(x), fnx = find(nx);
        if (edges[x][nx] == 1 && fx == fnx){
            res = false;
            break;
        }
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    edges.assign(n, vector<int>(n, 0));
    parents.assign(n, 0);
    for (vector<int> &row : edges){
        for (int &num : row){
            cin >> num;
        }
    }
    for (int i=0; i<n; i++){
        parents[i] = i;
    }
    bool ans = true;
    for (int i=0; i<n; i++){
        run(i);
    }
    for (int i=0; i<n; i++){
        if (!check(i)){
            ans = false;
            break;
        }
    }
    if (!ans){
        cout << 0 << '\n';
    }
    else {
        vector<vector<int>> res(n, vector<int>(0));
        unordered_set<int> sets;
        bool chk = true;
        for (int x=0; x<n; x++){
            int fx = find(x);
            res[fx].push_back(x);
            sets.insert(fx);
        }
        for (vector<int> &row : res){
            if (row.size() == 1){
                chk = false;
            }
        }
        if (!chk){
            cout << 0;
            return 0;
        }
        cout << sets.size() << '\n';
        for (vector<int> &row : res){
            if (row.empty())
                continue;
            sort(row.begin(), row.end());
            for (int i=0; i<row.size(); i++){
                if (i)  cout << ' ';
                cout << row[i] + 1;
            }
            cout << '\n';
        }
    }
}