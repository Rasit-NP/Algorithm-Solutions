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
        res.reserve(queries.size());
        freq.assign(50'001, 0);
        cnt.assign(50'001, 0);
        gcdCount.assign(50'001, 0);

        for (int num : nums){
            ++freq[num];
        }

        for (int i=1; i<=50'000; ++i){
            for (int d=i; d<=50'000; d+=i){
                cnt[i] += freq[d];
            }
        }

        for (int i=50'000; i>=1; --i){
            gcdCount[i] = (llong)cnt[i] * (cnt[i] - 1) / 2;
            for (int d=2*i; d<=50'000; d+=i){
                gcdCount[i] -= gcdCount[d];
            }
        }

        for (int i=0; i<50'000; ++i){
            gcdCount[i+1] += gcdCount[i];
        }

        for (llong query : queries){
            int idx = upper_bound(gcdCount.begin(), gcdCount.end(), query) - gcdCount.begin();
            res.emplace_back(idx);
        }

        return res;
    }
};