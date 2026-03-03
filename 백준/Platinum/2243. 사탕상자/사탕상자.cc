# include <iostream>
# include <vector>
# define MAX 1000000
# define SIZE 1<<20;
using namespace std;

struct SegTree{
    int size = SIZE;
    vector<int> tree;

    SegTree(void){
        this->tree.assign(2*size, 0);
    }

    int rangeSum(int idx){
        int a = size + 1, b = size + idx;
        int res=0;

        while (a<=b){
            if (a&1){
                res += tree[a];
                a++;
            }
            if (!(b&1)){
                res += tree[b];
                b--;
            }
            a >>= 1;
            b >>= 1;
        }

        return res;
    }
    
    int search(int value){
        int l = 0, r = MAX;
        while (r-l > 1){
            int mid = (l+r)/2;
            if (rangeSum(mid) >= value){
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }

    void insert(int idx, int v){
        idx += size;
        for (; idx > 0; idx >>= 1){
            tree[idx] += v;
        }
    }

    void extract(int idx){
        idx += size;
        for (; idx > 0; idx >>= 1){
            tree[idx] -= 1;
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    SegTree myTree = SegTree();

    while (n--){
        int order;  cin >> order;
        if (order == 1){
            int value;  cin >> value;
            int idx = myTree.search(value);
            cout << idx << '\n';
            myTree.extract(idx);
        }
        else if (order == 2){
            int idx, v; cin >> idx >> v;
            myTree.insert(idx, v);
        }
    }
}