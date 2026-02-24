# include <iostream>
# include <vector>
using namespace std;

int n, m, length;
vector<int> positions;

struct Tree{
    int size = 1;
    int head = m;
    vector<int> tree;

    Tree(int l){
        while (size < l){
            size <<= 1;
        }

        tree.assign(2*size, 0);
        for (int i = 0; i<n; i++){
            tree[i + m + size] = 1;
            positions[i+1] = i + m;
        }

        for (int i = size - 1; i>0; i--){
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }

    void pop(int idx){
        for (idx += size; idx > 0; idx >>= 1){
            tree[idx]--;
        }
    }

    int push(void){
        int idx = --head;
        for (idx += size; idx > 0; idx >>= 1){
            tree[idx]++;
        }

        return head;
    }

    int cnt(int l, int r){
        l += size;
        r += size;

        int res = 0;

        while (l<=r){
            if (l&1){
                res += tree[l];
                l++;
            }
            if (!(r&1)){
                res += tree[r];
                r--;
            }
            l >>= 1;
            r >>= 1;
        }

        return res;
    }
};

int get(Tree& tree, int v){
    int pos = positions[v];
    int res = tree.cnt(0, pos-1);
    if (res == 0){
        return res;
    }
    tree.pop(pos);
    positions[v] = tree.push();

    return res;
}

void run(){
    cin >> n >> m;
    length = n + m;

    positions.assign(n+1, 0);
    Tree tree = Tree(length);

    for (int i=0; i<m; i++){
        int b;  cin >> b;
        if (i)  cout << ' ';
        cout << get(tree, b);
    }
    cout << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int t;  cin >> t;
    while (t--){
        run();
    }
}