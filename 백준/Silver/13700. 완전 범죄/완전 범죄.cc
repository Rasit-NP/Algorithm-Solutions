# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s, d, f, b, k;
    cin >> n >> s >> d >> f >> b >> k;
    vector<int> buildings(n, 0);
    for (int i=0; i<k; i++){
        int x;
        cin >> x;
        buildings[x] = -1;
    }
    int dx[2] = {f, -b};
    queue<int> q;
    q.push(s);
    buildings[s] = 1;
    int ans = 0;
    while (q.size()){
        int x = q.front();
        q.pop();
        if (x==d){
            ans = buildings[x];
            break;
        }
        for (int i=0; i<2; i++){
            int nx = x + dx[i];
            if ((nx>=1 && nx<=n) && buildings[nx] == 0){
                q.push(nx);
                buildings[nx] = buildings[x] + 1;
            }
        }
    }
    if (ans)
        cout << ans-1 << '\n';
    else
        cout << "BUG FOUND\n";
}