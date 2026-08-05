# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> res;
        res.reserve(n);
        vector<int> isDeleted(n, 0);
        vector<vector<int>> edges(n, vector<int>(0));

        for (const auto& invocation : invocations){
            edges[invocation[0]].emplace_back(invocation[1]);
        }

        queue<int> q;
        q.emplace(k);
        isDeleted[k] = 1;
        bool chk = false;

        while (q.size()){
            int x = q.front();  q.pop();

            for (int nx : edges[x]){
                if (!isDeleted[nx]){
                    isDeleted[nx] = 1;
                    q.emplace(nx);
                }
            }
        }

        for (int x=0; x<n; x++){
            if (isDeleted[x] == 0){
                for (int nx : edges[x]){
                    if (isDeleted[nx] == 1){
                        isDeleted[nx] = 2;
                        chk = true;
                    }
                }
            }
        }
        
        if (chk){
            for (int x=0; x<n; x++){
                res.emplace_back(x);
            }
        }
        else {
            for (int x=0; x<n; x++){
                if (isDeleted[x] != 1){
                    res.emplace_back(x);
                }
            }
        }

        return res;
    }
};