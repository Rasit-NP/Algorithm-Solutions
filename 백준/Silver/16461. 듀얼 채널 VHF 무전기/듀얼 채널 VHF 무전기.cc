# include <iostream>
# include <queue>
# include <string>
# include <unordered_set>
using namespace std;

struct Data{
    int x;
    int dist;

    Data(int& x, int dist){
        this->x = x;
        this->dist = dist;
    }

    pair<int, int> inject(){
        return {x, dist};
    }
};

int getChannel(){
    string channel;
    for (int i=0; i<7; i++){
        char x; cin >> x;
        if (i != 3)
            channel.push_back(x);
    }

    return stoi(channel);
}

void solve(){
    int a, b, now, target;
    char ab;
    a = getChannel();
    b = getChannel();
    cin >> ab;
    if (ab == 'A')
        now = a;
    else
        now = b;
    target = getChannel();

    
    int ans = 6;
    
    for (int dx : {-20, 20}){
        unordered_set<int> sets;
        queue<Data> q;
        q.emplace(now, 0);

        while (q.size()){
            const auto [x, dist] = q.front().inject();     q.pop();
    
            if (dist == ans){
                break;
            }
    
            if (x == target){
                ans = dist;
                break;
            }
    
            if (x == a && sets.find(b) == sets.end()){
                q.emplace(b, dist+1);
                sets.insert(b);
            }
            else if (x == b && sets.find(a) == sets.end()){
                q.emplace(a, dist+1);
                sets.insert(a);
            }

            int nx = x + dx;
            if (nx > 146000)
                nx = 144000;
            else if (nx < 144000)
                nx = 146000;
            if (sets.find(nx) == sets.end()){
                q.emplace(nx, dist+1);
                sets.insert(a);
            }
        }
    }
    cout << ans << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        solve();
    }
}