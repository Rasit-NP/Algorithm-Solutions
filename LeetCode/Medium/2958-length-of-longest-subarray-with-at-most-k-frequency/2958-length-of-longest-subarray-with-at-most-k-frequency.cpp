# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int front = 0, tail = 0;
        unordered_map<int, int> freq;

        while (tail < n){
            int val = nums[tail++];
            ++freq[val];

            while (freq[val] > k){
                int now = nums[front];
                --freq[now];
                ++front;
            }

            res = max(res, tail-front);
        }

        return res;
    }
};