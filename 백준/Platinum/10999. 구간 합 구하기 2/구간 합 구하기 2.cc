# include <iostream>
# include <vector>
using namespace std;


int n, m, k, size_of_tree=1;
vector<long long> tree;
vector<long long> lazy;

void init(void) {
    cin >> n >> m >> k;
    while (size_of_tree < n){
        size_of_tree *= 2;
    }
    tree.assign(2*size_of_tree, 0);
    lazy.assign(2*size_of_tree, 0);

    for (int i=size_of_tree; i<size_of_tree+n; i++){
        cin >> tree[i];
    }
    for (int i=size_of_tree-1; i>0; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void propagate(int node, int start, int end) {
    if (lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int l, int r, long long value) {
    propagate(node, l, r);
    tree[node] += (end - start + 1) * value;
    if (l == start && end == r){
        if (start != end){
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return;
    }
    
    int mid = (l + r) / 2;

    if (end <= mid){
        update(node*2, start, end, l, mid, value);
    }
    else if (start > mid){
        update(node*2+1, start, end, mid+1, r, value);
    }
    else {
        update(node*2, start, mid, l, mid, value);
        update(node*2+1, mid+1, end, mid+1, r, value);
    }
}

long long get(int node, int start, int end, int l, int r) {
    propagate(node, l, r);
    
    if (start == l && end == r){
        return tree[node];
    }
    else{
        int mid = (l+r)/2;
        if (end <= mid){
            return get(2*node, start, end, l, mid);
        }
        else if (start > mid){
            return get(2*node+1, start, end, mid+1, r);
        }
        else {
            return get(2*node, start, mid, l, mid) + get(2*node+1, mid+1, end, mid+1, r);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();
    int q;
    int a, b;
    long long c;
    for (int i=0; i<m+k; i++){
        cin >> q;
        if (q == 1){
            cin >> a >> b >> c;
            update(1, size_of_tree+a-1, size_of_tree+b-1, size_of_tree, 2*size_of_tree-1, c);
        }
        else if (q == 2){
            cin >> a >> b;
            cout << get(1, size_of_tree+a-1, size_of_tree+b-1, size_of_tree, 2*size_of_tree-1) << '\n';
        }
    }
}