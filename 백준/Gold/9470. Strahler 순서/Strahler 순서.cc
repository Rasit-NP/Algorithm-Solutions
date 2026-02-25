# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int m, p;

void run(int tc){
    cin >> m >> p;

    vector<int> cnt_parents(m+1, 0);
    vector<vector<int>> childs(m+1, vector<int>(0));
    vector<vector<int>> parents(m+1, vector<int>(0));
    vector<int> strahler(m+1, 0);
    queue<int> q;

    for (int i=0; i<p; i++){
        int a, b;   cin >> a >> b;
        cnt_parents[b]++;
        childs[a].push_back(b);
        parents[b].push_back(a);
    }

    for (int i=1; i<=m; i++){
        if (cnt_parents[i] == 0){
            q.push(i);
            strahler[i] = 1;
            cnt_parents[i] = -1;
        }
    }

    while (q.size()){
        int x = q.front();  q.pop();
        for (const int& nx : childs[x]){
            if (cnt_parents[nx] == -1){
                continue;
            }
            cnt_parents[nx]--;
            if (cnt_parents[nx] == 0){
                q.push(nx);
                int level = 0;
                bool duplicated = false;
                for (const int& parent : parents[nx]){
                    if (strahler[parent] > level){
                        level = strahler[parent];
                        duplicated = false;
                    }
                    else if (strahler[parent] == level){
                        duplicated = true;
                    }
                }

                strahler[nx] = level + (duplicated ? 1 : 0);
                cnt_parents[nx] = -1;
            }
        }
    }

    cout << tc << ' ' << strahler[m] << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int k;  cin >> k;
        run(k);
    }
}