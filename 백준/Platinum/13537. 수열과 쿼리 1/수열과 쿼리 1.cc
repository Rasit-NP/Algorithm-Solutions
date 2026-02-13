# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct Node{
    vector<int> list;
    int size;

    Node(void){
        this->size = 0;
    }

    void push(int num){
        this->list.push_back(num);
        size++;
    }

    void merge(const Node& a, const Node& b){
        int idxA = 0, idxB = 0;
        if (a.size == 0){
            for (int num : b.list){
                this->push(num);
            }
            return;
        }
        else if (b.size == 0){
            for (int num : a.list){
                this->push(num);
            }
            return;
        }
        while(this->size < a.size + b.size){
            if (idxA == a.size){
                this->push(b.list[idxB++]);
            }
            else if (idxB == b.size){
                this->push(a.list[idxA++]);
            }
            else if (a.list[idxA] < b.list[idxB]){
                this->push(a.list[idxA++]);
            }
            else {
                this->push(b.list[idxB++]);
            }
        }
    }

    int count(int k) {
        return this->list.size() - (upper_bound(this->list.begin(), this->list.end(), k) - this->list.begin());
    }

};

struct SegTree{
    vector<Node> tree;
    int size = 1;

    SegTree(int n){
        while (size < n){
            this->size <<= 1;
        }
        this->tree.assign(size<<1, Node());
        this->input(n);
    }

    void input(int n){
        for (int i=0; i<n; i++){
            int num;    cin >> num;
            this->tree[size + i].push(num);
        }
        for (int i=size-1; i>0; i--){
            this->tree[i].merge(this->tree[2*i], this->tree[2*i+1]);
        }
    }

    int count(int i, int j, int k){
        i += this->size - 1;
        j += this->size - 1;
        int res = 0;
        while (i<=j){
            if (i&1){
                res += this->tree[i].count(k);
                i++;
            }
            if (!(j&1)){
                res += this->tree[j].count(k);
                j--;
            }
            i >>= 1;
            j >>= 1;
        }
        return res;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    SegTree myTree = SegTree(n);
    int m;  cin >> m;
    while (m--){
        int i, j, k;    cin >> i >> j >> k;
        cout << myTree.count(i, j, k) << '\n';
    }
}