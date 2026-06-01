# include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int res = 0;
        int state = 1;
        sort(cost.begin(), cost.end());

        for (int i=n-1; i>=0; i--){
            if (state++){
                res += cost[i];
            }
            state %= 3;
        }

        return res;
    }
};