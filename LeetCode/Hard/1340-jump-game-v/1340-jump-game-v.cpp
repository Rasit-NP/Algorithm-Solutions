# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n, d;
    vector<int> memo;

    int game(vector<int>& arr, int x){
        if (memo[x] != -1){
            return memo[x];
        }

        int res = 1;
        int lim = min(n, x+d+1);

        for (int nx=x+1; nx<lim; nx++){
            if (arr[nx] < arr[x]){
                res = max(res, game(arr, nx)+1);
            }
            else {
                break;
            }
        }

        lim = max(0, x-d);

        for (int nx=x-1; nx>=lim; nx--){
            if (arr[nx] < arr[x]){
                res = max(res, game(arr, nx)+1);
            }
            else {
                break;
            }
        }

        memo[x] = res;

        return res;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        n = arr.size();
        this->d = d;
        memo.assign(n, -1);

        for (int i=0; i<n; i++){
            ans = max(ans, game(arr, i));
        }

        return ans;
    }
};