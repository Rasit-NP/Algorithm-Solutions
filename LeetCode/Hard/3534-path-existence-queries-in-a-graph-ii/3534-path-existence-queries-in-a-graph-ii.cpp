# include <vector>
# include <cmath>
# include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
private:
    int n, maxDiff;
    int LOG;
    vector<int> res;
    vector<pii> num_idx;
    vector<vector<int>> nextNode;

    void init(vector<int>& nums){
        for (int i=0; i<n; i++){
            num_idx.emplace_back(nums[i], i);
        }
        LOG = (int)log2(n);

        sort(num_idx.begin(), num_idx.end());

        nextNode.assign(LOG + 1, vector<int>(n, -1));

        for (const auto [num, idx] : num_idx){
            int next = upper_bound(num_idx.begin(), num_idx.end(), make_pair(num+maxDiff, n)) - num_idx.begin() - 1;
            nextNode[0][idx] = num_idx[next].second;
        }

        for (int d=1; d<=LOG; d++){
            for (int i=0; i<n; i++){
                nextNode[d][i] = nextNode[d-1][nextNode[d-1][i]];
            }
        }
    }

    void solve(int u, int v, const vector<int>& nums){
        if (nums[u] > nums[v]){
            swap(u, v);
        }
        else if (u == v){
            res.emplace_back(0);
            return;
        }

        int cnt = 0;

        for (int d=LOG; d>=0; d--){
            int next = nextNode[d][u];
            if (nums[next] < nums[v]) {
                cnt += (1 << d);
                u = next;
            }
        }

        if (nums[u] + maxDiff >= nums[v]){
            res.emplace_back(cnt + 1);
        }
        else {
            res.emplace_back(-1);
        }
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        this->n = n;
        this->maxDiff = maxDiff;
        
        init(nums);

        res.reserve(queries.size());
        for (const vector<int>& query : queries){
            solve(query[0], query[1], nums);
        }

        return res;
    }
};