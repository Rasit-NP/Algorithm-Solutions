# include <vector>
# include <queue>

class Solution {
private:
    int n;
    queue<int> q;
    vector<bool> visited;
public:
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        visited.assign(n, false);

        q.push(start);
        visited[start] = true;

        while(q.size()){
            int x = q.front();  q.pop();
            int val = arr[x];
            if (val == 0){
                return true;
            }
            for (int dx : {-val, val}){
                int nx = x + dx;
                if (nx < 0 || nx >= n){
                    continue;
                }
                if (visited[nx]){
                    continue;
                }

                q.push(nx);
                visited[nx] = true;
            }
        }

        return false;
    }
};