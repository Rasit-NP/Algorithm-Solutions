# include <vector>
# include <algorithm>
using namespace std;

struct Data{
    long long val;
    vector<int> list;

    Data(): Data(0, {}){}
    Data(long long val, vector<int> list): val(val), list(list){}
    Data(vector<int>& interval): Data(interval[2], {interval[3]}){}

    void plus(vector<int>& interval){
        val += interval[2];
        list.emplace_back(interval[3]);

        sort(list.begin(), list.end());
    }

    bool operator<(const Data& other) const {
        return val != other.val ? val < other.val : list > other.list;
    }
};

class Solution {
private:
    int findPos(int target, vector<vector<int>>& intervals){
        int l = -1, r = intervals.size();

        while (r-l > 1){
            int mid = (l+r)/2;
            if (intervals[mid][0] > target)
                r = mid;
            else
                l = mid;
        }
        return r;
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i=0; i<n; i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });

        vector<vector<Data>> dp(n+1, vector<Data>(5));
        for (int i=n-1; i>=0; --i){
            int r = intervals[i][1];
            int pos = findPos(r, intervals);
            for (int t=1; t<5; ++t){
                Data d1 = dp[i+1][t];
                Data d2 = dp[pos][t-1];
                d2.plus(intervals[i]);

                dp[i][t] = max(d1, d2);
            }
        }

        Data res = dp[0][0];
        for (int i=1; i<5; ++i){
            res = max(res, dp[0][i]);
        }

        return res.list;
    }
};