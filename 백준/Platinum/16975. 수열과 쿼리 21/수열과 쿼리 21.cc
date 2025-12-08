# include <iostream>
# include <vector>
using namespace std;

int n, m, size_of_tree=1;
vector<long long> tree;

void init(void){
    cin >> n;
    while (size_of_tree<n){
        size_of_tree = size_of_tree << 1;
    }
    tree.assign(2*size_of_tree, 0);
    for (int i=0; i<n; i++){
        cin >> tree[size_of_tree+i];
    }
}

void propagation(int node, int l, int r){
    if (l == r) return;
    if (tree[node]){
        tree[2*node] += tree[node];
        tree[2*node + 1] += tree[node];
        tree[node] = 0;
    }
}

void update(int node, int start, int end, int l, int r, int val){
    propagation(node, l, r);
    if (start==l && end==r){
        if (l != r){
            tree[2*node] += val;
            tree[2*node + 1] += val;
        }
        else{
            tree[node] += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    if (end <= mid){
        update(2*node, start, end, l, mid, val);
    }
    else if (start > mid){
        update(2*node+1, start, end, mid+1, r, val);
    }
    else {
        update(2*node, start, mid, l, mid, val);
        update(2*node+1, mid+1, end, mid+1, r, val);
    }
}

long long get(int node, int target, int l, int r){
    propagation(node, l, r);
    if (l == r){
        return tree[node];
    }

    int mid = (l+r)/2;
    if (target <= mid) {
        return get(2*node, target, l, mid);
    }
    else {
        return get(2*node + 1, target, mid+1, r);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();
    cin >> m;
    int q, i, j, k, x;
    for (int idx=0; idx<m; idx++){
        cin >> q;
        if (q == 1){
            cin >> i >> j >> k;
            update(1, size_of_tree+i-1, size_of_tree+j-1, size_of_tree, 2*size_of_tree-1, k);
        }
        else if (q == 2){
            cin >> x;
            cout << get(1, size_of_tree+x-1, size_of_tree, 2*size_of_tree-1) << '\n';
        }
    }
}