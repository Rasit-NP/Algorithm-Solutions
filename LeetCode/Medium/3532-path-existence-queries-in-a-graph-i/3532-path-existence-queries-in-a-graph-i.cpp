# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<bool> res;
    vector<int> maxEdge;
    vector<int> range;

    int getRange(int x){
        if (range[x] != -1){
            return range[x];
        }

        if (maxEdge[x] == x){
            range[x] = x;
            return x;
        }

        int val = getRange(maxEdge[x]);
        range[x] = val;
        return val;
    }

    bool solve(int u, int v){
        int a = min(u, v), b = max(u, v);

        if (b <= range[a]){
            return true;
        }
        else {
            return false;
        }
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        this->n = n;
        maxEdge.assign(n, 0);
        range.assign(n, -1);
        res.reserve(queries.size());

        for (int l=0, r=0; l<n; l++){
            while (r < n-1 && nums[r+1]-nums[l] <= maxDiff){
                ++r;
            }
            maxEdge[l] = r;
        }

        for (int i=0; i<n; i++){
            range[i] = getRange(i);
        }

        for (const auto& q : queries){
            res.emplace_back(solve(q[0], q[1]));
        }

        return res;
    }
};