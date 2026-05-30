# include <algorithm>
# include <vector>
using namespace std;

struct Node {
    int leftObst, rightObst, maxGap;
};

class SegTree {
private:
    vector<Node> tree;
    int N;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.leftObst  = (L.leftObst  != -1) ? L.leftObst  : R.leftObst;
        res.rightObst = (R.rightObst != -1) ? R.rightObst : L.rightObst;
        res.maxGap    = max(L.maxGap, R.maxGap);
        if (L.rightObst != -1 && R.leftObst != -1)
            res.maxGap = max(res.maxGap, R.leftObst - L.rightObst);
        return res;
    }

public:
    SegTree() : N(0) {}

    SegTree(int maxPos) {
        N = 1;
        while (N <= maxPos) N <<= 1;
        tree.assign(N * 2, {-1, -1, 0});
    }

    void update(int pos) {
        int i = N + pos;
        tree[i] = {pos, pos, 0};
        for (i >>= 1; i >= 1; i >>= 1)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
    
    Node query(int l, int r) {
        Node resL = {-1, -1, 0}, resR = {-1, -1, 0};
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = merge(resL, tree[l++]);
            if (r & 1) resR = merge(tree[--r], resR);
        }
        return merge(resL, resR);
    }
};

class Solution {
    SegTree tree;

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        tree = SegTree(50001);
        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                tree.update(q[1]);
            }
            else {
                int x = q[1], sz = q[2];
                Node res = tree.query(1, x);

                int maxGap;
                if (res.leftObst == -1) {
                    maxGap = x;
                }
                else {
                    maxGap = max({
                        res.maxGap,
                        res.leftObst,
                        x - res.rightObst
                    });
                }

                ans.push_back(maxGap >= sz);
            }
        }
        return ans;
    }
};