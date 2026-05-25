# include <string>
# include <queue>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        int latest = 0;
        while (q.size()){
            int x = q.front();  q.pop();
            if (x == n-1){
                return true;
            }
            int mx = min(x + maxJump, n-1);
            for (int nx=max(latest+1, x+minJump); nx<=mx; nx++){
                if (s[nx] == '0'){
                    q.push(nx);
                }
                latest = nx;
            }
        }

        return false;
    }
};