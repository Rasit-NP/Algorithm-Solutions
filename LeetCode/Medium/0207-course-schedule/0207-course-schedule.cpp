# include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> cntParents;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.assign(numCourses, vector<int>(0));
        cntParents.assign(numCourses, 0);

        for (vector<int>& req : prerequisites){
            int a = req[0], b = req[1];
            edges[b].push_back(a);
            cntParents[a]++;
        }

        int cnt = 0;
        while (cnt < numCourses){
            vector<int> reserved;
            for (int i=0; i<numCourses; i++){
                if (cntParents[i] == 0){
                    reserved.push_back(i);
                    ++cnt;
                    cntParents[i] = -1;
                }
            }
            if (reserved.empty()){
                return false;
            }

            for (int x : reserved){
                for (int nx : edges[x]){
                    cntParents[nx]--;
                }
            }
        }

        return true;
    }
};