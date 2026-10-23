# include <vector>
# include <climits>
# include <queue>
# include <algorithm>
using namespace std;

struct Req {
    int start;
    int length;
    
    Req(): start(0), length(0){}
    
    Req(int start, int length) : start(start), length(length){}
};

int solution(int k, int n, vector<vector<int>> reqs) {
    vector<vector<Req>> rs(k+1, vector<Req>(0));
    
    for (vector<int>& req : reqs){
        int a = req[0], b = req[1], c = req[2];
        
        rs[c].emplace_back(a, b);
    }
    
    vector<vector<int>> getWaitingTimes(k+1, vector<int>(n+1, 1 << 20));
    
    for (int _k=1; _k<=k; ++_k){
        if (rs[_k].empty()){
            for (int num=0; num<=n; ++num){
                getWaitingTimes[_k][num] = 0;
            }
            continue;
        }
        
        for (int num=1; num<=n; ++num){
            int waitingTime = 0;
            
            int nowIn = 0;
            int nowTime = 0;
            priority_queue<int> endAt;
            
            for (Req& req : rs[_k]){
                if (nowIn < num){
                    ++nowIn;
                    nowTime = req.start;
                    endAt.emplace(-(nowTime + req.length));
                }
                else {
                    int end = -endAt.top();     endAt.pop();
                    
                    nowTime = end;
                    
                    if (req.start < nowTime){
                        waitingTime += (nowTime - req.start);
                    }
                    else {
                        nowTime = req.start;
                    }
                    
                    endAt.emplace(-(nowTime + req.length));
                }
            }
            
            getWaitingTimes[_k][num] = waitingTime;
        }
    }
    
    vector<vector<int>> dp(k+1, vector<int>(n+1, INT_MAX));
    
    for (int i=1; i<=n; ++i){
        dp[1][i] = getWaitingTimes[1][i];
    }
    
    for (int i=1; i<k; ++i){
        for (int j=i; j<=n; ++j){
            for (int j2=j+1; j2<=n; ++j2){
                dp[i+1][j2] = min(dp[i+1][j2], dp[i][j] + getWaitingTimes[i+1][j2-j]);
            }
        }
    }
    
    return dp[k][n];
}
    
    