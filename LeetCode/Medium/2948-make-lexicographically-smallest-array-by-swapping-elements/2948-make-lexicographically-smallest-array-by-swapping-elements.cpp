# include <vector>
# include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
private:
    vector<int> res;

    void adapt(vector<int>& position, vector<int>& value){
        sort(position.begin(), position.end());

        for (int i=0; i<position.size(); i++){
            res[position[i]] = value[i];
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        res.assign(n, 0);
        vector<pii> sortedNums;
        for (int i=0; i<n; i++){
            int num = nums[i];
            sortedNums.emplace_back(num, i);
        }

        sort(sortedNums.begin(), sortedNums.end());

        vector<int> position, value;

        for (int i=0; i<n; i++){
            int num = sortedNums[i].first, idx = sortedNums[i].second;
            if (position.size() && num - value.back() > limit) {
                adapt(position, value);
                position.clear();
                value.clear();
            }
            position.emplace_back(idx);
            value.emplace_back(num);
        }
        if (position.size()){
            adapt(position, value);
        }

        return res;
    }
};