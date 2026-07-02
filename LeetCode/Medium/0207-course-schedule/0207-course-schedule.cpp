# include <vector>
# include <queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> cntParents;
    queue<int> q;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.assign(numCourses, vector<int>(0));
        cntParents.assign(numCourses, 0);

        for (vector<int>& req : prerequisites){
            int a = req[0], b = req[1];
            edges[b].push_back(a);
            cntParents[a]++;
        }

        for (int i=0; i<numCourses; i++){
            if (cntParents[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        while (q.size()){
            ++cnt;
            int x = q.front();  q.pop();

            for (int nx : edges[x]){
                if (--cntParents[nx] == 0){
                    q.push(nx);
                }
                cntParents[x]--;
            }
        }

        return cnt == numCourses;
    }
};