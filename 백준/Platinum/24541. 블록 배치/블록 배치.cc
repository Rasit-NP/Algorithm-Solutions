# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;


int n, x, tSize;
vector<int> blocks;
vector<int> sorted;
vector<int> dp;

struct SegTree{
    static vector<int> blocks;
    vector<int> tree;
    
    SegTree(){
        this->tree.assign(2*tSize, 0);
    }
    
    int get(int a, int b){
        a += tSize;
        b += tSize;
        int maximum = 0;
        while (a <= b){
            if (a&1){
                maximum = max(this -> tree[a], maximum);
                a += 1;
            }
            if (!(b&1)){
                maximum = max(this -> tree[b], maximum);
                b -= 1;
            }
            a >>= 1;
            b >>= 1;
        }
        return maximum;
    }
    
    void update(int x, int v){
        x += tSize;
        while (x > 0){
            this -> tree[x] = max(v, this -> tree[x]);
            x >>= 1;
        }
    }
};

vector<int> SegTree::blocks;

void trans(void){
    sort(blocks.begin(), blocks.end());

    for (int height : blocks){
        if (!sorted.size()){
            sorted.push_back(height);
        }
        else if (*(sorted.end()-1) < height){
            sorted.push_back(height);
        }
    }
}

void init(void){
    cin >> n >> x;

    SegTree::blocks.assign(n, 0);
    blocks.assign(n, 0);
    for (int i=0; i<n; i++){
        cin >> SegTree::blocks[i];
        blocks[i] = SegTree::blocks[i];
    }

    trans();

    tSize = 1;
    while (tSize < sorted.size()){
        tSize <<= 1;
    }
}

int getIdx(int h){
    int idx = lower_bound(sorted.begin(), sorted.end(), h) - sorted.begin();
    return idx;
}

int cal(int d){
    dp.assign(n, 0);

    SegTree segTree = SegTree();

    int height = segTree.blocks[0];
    dp[0] = 1;
    segTree.update(getIdx(height), 1);

    for (int i=1; i<n; i++){
        height = segTree.blocks[i];
        int mini = max(sorted[0], height - d), maxi = min(height + d, *(sorted.end() - 1));
        int m = getIdx(mini), M = getIdx(maxi);

        if (sorted[M] != maxi){
            M--;
        }
        
        dp[i] = segTree.get(m, M) + 1;

        segTree.update(getIdx(height), dp[i]);
    }

    int res = 0;
    for (int num : dp){
        res = max(res, num);
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    init();

    int l = -1, r = 1000000000;
    while (r-l > 1){
        int mid = (l+r) >> 1;
        int cnt = cal(mid);

        if (cnt >= x){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r;
}