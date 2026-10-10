# include <vector>
# include <algorithm>
using namespace std;
using Long = long long;

class Solution {
private:
    int n;
    Long k;
    vector<Long> diff;

    Long getTotalDiff(int trial){
        Long count = 0;
        for (int num : diff){
            if (num > trial){
                count += num - trial;
            }
        }

        return count;
    }
public:
    Long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        n = nums1.size();
        k = k1 + k2;
        diff.assign(n, 0);

        Long sum = 0;

        for (int i=0; i<n; ++i){
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }

        if (sum <= k){
            return 0;
        }

        sort(diff.begin(), diff.end());

        int l = -1, r = 200'000;

        while (r-l > 1){
            int mid = (l+r)/2;

            if (getTotalDiff(mid) <= k){
                r = mid;
            }
            else {
                l = mid;
            }
        }

        Long res = 0;

        for (int i=n-1; i>=0; --i){
            if (k > 0 && diff[i] > r){
                int val = min(k, diff[i] - r);
                k -= val;
                diff[i] -= val;
            }
            res += diff[i] * diff[i];
            cout << diff[i] << endl;
        }

        if (k){
            res -= k * r * r;
            res += k * max(0, (r-1)) * max(0, (r-1));
        }

        return res;
    }
};