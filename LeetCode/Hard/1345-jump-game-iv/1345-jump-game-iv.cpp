# include <vector>
# include <queue>
# include <unordered_map>
# include <unordered_set>
using namespace std;

class Solution {
private:
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> edges;
        vector<int> visited(n, -1);
        queue<int> q;
        unordered_set<int> passed;

        for (int i=0; i<n; i++){
            int num = arr[i];
            edges[num].push_back(i);
        }

        q.push(0);
        visited[0] = 0;

        while (q.size()){
            int x = q.front();  q.pop();
            if (x == n-1){
                return visited[x];
            }

            int val = arr[x];
            if (passed.find(val) == passed.end()){
                for (int nx : edges[val]){
                    if (visited[nx] == -1){
                        visited[nx] = visited[x] + 1;
                        q.push(nx);
                    }
                }
                passed.insert(val);
            }

            for (int dx : {-1, 1}){
                int nx = x + dx;
                if (nx < 0 || nx >= n){
                    continue;
                }
                if (visited[nx] == -1){
                    visited[nx] = visited[x] + 1;
                    q.push(nx);
                }
            }
        }
        return visited[n-1];
    }
};