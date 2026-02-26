# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

int n, m;

struct Node{
    int routeNo = 0;
    int value;

    Node(){
        value = INT_MAX;
    }
    
    bool operator <(const Node& n) const {
        if (this->value < n.value){
            return true;
        }
        return false;
    }
};

struct SegTree{
    int startNo;
    int size = 1;
    vector<Node> tree;

    SegTree(int no, int n){
        startNo = no;
        while (size < n){
            size <<= 1;
        }

        tree.assign(2*size, Node());

        for (int idx = 0; idx < n; idx++){
            int v;  cin >> v;
            tree[size + idx].routeNo = startNo + idx;
            tree[size + idx].value = v;
        }

        for (int idx = size-1; idx>0; idx--){
            tree[idx] = min(tree[2*idx], tree[2*idx+1]);
        }
    }

    void update(int x, int y){
        int idx = size + x - startNo;
        tree[idx].value = y;

        for (idx>>=1; idx > 0; idx >>= 1){
            tree[idx] = min(tree[2*idx], tree[2*idx + 1]);
        }
    }

    int getMin(){
        return tree[1].routeNo;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    cin >> n >> m;

    SegTree tree1 = SegTree(1, n);
    SegTree tree2 = SegTree(n+1, m);

    int k;  cin >> k;
    while (k--){
        char order; cin >> order;
        if (order == 'U'){
            int x, y;   cin >> x >> y;
            if (x > n){
                tree2.update(x, y);
            }
            else {
                tree1.update(x, y);
            }
        }
        else if (order == 'L'){
            cout << tree1.getMin() << ' ' << tree2.getMin() << '\n';
        }
    }
}