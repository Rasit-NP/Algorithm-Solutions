# include <queue>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

class Solution {
private:
    int res = 0;
    int len;
    vector<int> heights;
    priority_queue<pair<int, int>> pq;
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        len = restrictions.size();
        if (len == 0){
            return n-1;
        }
        restrictions.reserve(len++);
        restrictions.push_back({1, 0});
        heights.assign(len, INT_MAX);

        sort(restrictions.begin(), restrictions.end());

        for (int i=0; i<len; i++){
            restrictions[i].push_back(i);
        }

        for (vector<int>& restriction : restrictions){
            pq.push({-restriction[1], restriction[2]});
            heights[restriction[2]] = restriction[1];
        }
        heights[0] = 0;

        while (pq.size()){
            pair<int, int> data = pq.top();   pq.pop();
            int h = -data.first, x = data.second;
            int id = restrictions[x][0];

            for (int dx : {-1, 1}){
                int nx = x + dx;
                if (nx < 0 || nx >= len)
                    continue;
                vector<int>& restriction = restrictions[nx];
                int nId = restriction[0];
                int nh = h + abs(id - nId);
                if (nh < heights[nx]){
                    heights[nx] = nh;
                    pq.push({-nh, nx});
                }
            }
        }

        for (int i=0; i<len-1; i++){
            int left = restrictions[i][0];
            int right = restrictions[i+1][0];
            int diff = abs(left - right);
            int dh = abs(heights[i] - heights[i+1]);

            diff -= dh;
            res = max(res, max(heights[i], heights[i+1]) + diff/2);
        }

        int x = restrictions.back()[2];
        int id = restrictions[x][0];
        if (id < n){
            res = max(res, heights[x] + (n-id));
        }

        return res;
    }
};