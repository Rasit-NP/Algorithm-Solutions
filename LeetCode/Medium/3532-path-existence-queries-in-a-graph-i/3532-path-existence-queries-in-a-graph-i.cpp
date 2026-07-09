# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    vector<bool> res;
    vector<int> group;

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        res.reserve(queries.size());
        group.assign(n, 0);

        for (int i=1; i<n; i++){
            if (nums[i] - nums[i-1] <= maxDiff){
                group[i] = group[i-1];
            }
            else {
                group[i] = group[i-1] + 1;
            }
        }

        for (const auto& q : queries){
            res.emplace_back(group[q[0]] == group[q[1]]);
        }

        return res;
    }
};