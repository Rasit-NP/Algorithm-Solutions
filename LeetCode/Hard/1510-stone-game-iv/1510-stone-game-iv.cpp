# include <vector>
using namespace std;

namespace {
int sq(int x){
    return x*x;
}
};

class Solution {
private:
    vector<int> memo;

    int play(int x){
        if (memo[x] != -1)
            return memo[x];
        
        for (int i=1; sq(i)<=x; i++){
            if (!play(x-sq(i))){
                memo[x] = 1;
                return memo[x];
            }
        }

        memo[x] = 0;
        return 0;
    }
public:
    bool winnerSquareGame(int n) {
        memo.assign(n+1, -1);
        memo[0] = 0;

        int res = play(n);

        return res;
    }
};