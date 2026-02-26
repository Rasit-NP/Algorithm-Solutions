# include <iostream>
# include <vector>
# include <tuple>
# include <queue>
# include <climits>
using namespace std;

struct Edge{
    int target, cost;

    Edge(int b, int c){
        target = b;
        cost = c;
    }
};

struct Node{
    bool isPitfall = false;
    vector<Edge> edges_normal;
    vector<Edge> edges_pitfall[2];

    Node(){}
};

struct Nodes{
    vector<Node> nodes;

    Nodes(int n){
        this -> nodes.assign(n, Node());
    }

    Node& operator[] (int idx){
        return this -> nodes[idx-1];
    }
};

int n, m, k, l, p;

Nodes init(void){
    cin >> n >> m >> k >> l >> p;
    Nodes nodes = Nodes(n);

    for (int i=0; i<k; i++){
        int v;  cin >> v;
        nodes[v].isPitfall = true;
    }

    for (int i=0; i<m-l; i++){
        int a, b, c;    cin >> a >> b >> c;
        nodes[a].edges_normal.push_back(Edge(b, c));
    }

    for (int i=0; i<l; i++){
        int a, b, c;    cin >> a >> b >> c;
        nodes[a].edges_pitfall[0].push_back(Edge(b, c));
        nodes[b].edges_pitfall[1].push_back(Edge(a, c));
    }

    return nodes;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    Nodes nodes = init();

    int s, e;   cin >> s >> e;

    priority_queue<tuple<int, int, int>> pq;
    vector<vector<int>> visited(n+1, vector<int>(2*p, INT_MAX));

    pq.push({0, s, 0});
    visited[s][0] = 0;

    int ans = -1;

    while (pq.size()){
        auto [t, x, pressed] = pq.top();     pq.pop();
        t = -t;
        if (t > visited[x][pressed]){
            continue;
        }
        if (x == e){
            ans = t;
            break;
        }
        const Node& node = nodes[x];
        int np = pressed + (node.isPitfall ? 1 : 0);
        np %= (2*p);
        for (Edge edge : node.edges_normal){
            int nx = edge.target, nt = t + edge.cost;
            if (visited[nx][np] > nt){
                visited[nx][np] = nt;
                pq.push({-nt, nx, np});
            }
        }

        for (Edge edge : node.edges_pitfall[np >= p]){
            int nx = edge.target, nt = t + edge.cost;
            if (visited[nx][np] > nt){
                visited[nx][np] = nt;
                pq.push({-nt, nx, np});
            }
        }

    }

    cout << ans;
}