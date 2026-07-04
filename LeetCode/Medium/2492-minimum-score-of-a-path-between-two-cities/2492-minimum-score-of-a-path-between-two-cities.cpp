# include <queue>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> visited(n+1, 0);
        vector<vector<pair<int, int>>> edges(n+1, vector<pair<int, int>>(0));

        for (vector<int>& road : roads){
            int a = road[0], b = road[1], dist = road[2];
            edges[a].emplace_back(b, dist);
            edges[b].emplace_back(a, dist);
        }

        queue<int> q;
        int minDist = 100000;
        q.push(1);
        visited[1] = 1;

        while (q.size()){
            int x = q.front();  q.pop();

            for (const auto& [nx, dist] : edges[x]){
                minDist = min(minDist, dist);
                if (visited[nx] == 0){
                    visited[nx] = 1;
                    q.push(nx);
                }
            }
        }

        return minDist;
    }
};