# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
public:
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>> edges(n, vector<int>(0));
        vector<int> visited(n, -1);
        visited[0] = 0;

        for (int i=0; i<n; i++){
            if (visited[i] == -1){
                continue;
            }
            for (int j=i+1; j<n; j++){
                if (abs(nums[j]-nums[i]) <= target){
                    visited[j] = max(visited[j], visited[i] + 1);
                }
            }
        }

        return visited[n-1];
    }
};