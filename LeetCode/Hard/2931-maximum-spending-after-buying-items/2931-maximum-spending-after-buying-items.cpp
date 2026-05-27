# include <vector>

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;
        int n = values.size(), m = values[0].size();
        int last = n*m;

        vector<int> nowIdx(n, m-1);

        for (int day=1; day<=last; day++){
            int minVal = 1000001;
            int minShop;

            for (int shop=0; shop<n; shop++){
                int idx = nowIdx[shop];
                if (idx < 0){
                    continue;
                }
                if(values[shop][idx] < minVal){
                    minVal = values[shop][idx];
                    minShop = shop;
                }
            }

            res += (long long)minVal * day;
            --nowIdx[minShop];
        }

        return res;
    }
};