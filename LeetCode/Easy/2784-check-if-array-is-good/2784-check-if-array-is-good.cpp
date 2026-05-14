# include <vector>
using namespace std;

class Solution {
private:
    int n;
public:
    bool isGood(vector<int>& nums) {
        n = nums.size() - 1;
        vector<int> cnt(n+1, 0);
        for (int num : nums){
            if (num > n){
                return false;
            }
            ++cnt[num];
        }

        for (int i=1; i<=n; i++){
            if (i<n && cnt[i]!=1){
                return false;
            }
            if (i==n && cnt[i]!=2){
                return false;
            }
        }
        return true;
    }
};