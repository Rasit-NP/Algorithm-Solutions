# include <vector>
# include <algorithm>
using namespace std;
typedef long long llong;

class Solution {
private:
    vector<int> freq;
    vector<int> cnt;
    vector<llong> gcdCount;
    vector<int> res;
public:
    vector<int> gcdValues(vector<int>& nums, vector<llong>& queries) {
        int MAX = *max_element(nums.begin(), nums.end());
        
        res.reserve(queries.size());
        freq.assign(MAX+1, 0);
        cnt.assign(MAX+1, 0);
        gcdCount.assign(MAX+1, 0);


        for (int num : nums){
            ++freq[num];
        }

        for (int i=1; i<=MAX; ++i){
            for (int d=i; d<=MAX; d+=i){
                cnt[i] += freq[d];
            }
        }

        for (int i=MAX; i>=1; --i){
            gcdCount[i] = (llong)cnt[i] * (cnt[i] - 1) / 2;
            for (int d=2*i; d<=MAX; d+=i){
                gcdCount[i] -= gcdCount[d];
            }
        }

        for (int i=0; i<MAX; ++i){
            gcdCount[i+1] += gcdCount[i];
        }

        for (llong query : queries){
            int idx = upper_bound(gcdCount.begin(), gcdCount.end(), query) - gcdCount.begin();
            res.emplace_back(idx);
        }

        return res;
    }
};