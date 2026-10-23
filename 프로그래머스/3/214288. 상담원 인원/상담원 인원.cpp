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

int N;
int K;
int res = 1 << 25;
int now = 0;
vector<vector<int>> getWaitingTimes;

void backTrack(int k){
    if (k == K){
        res = min(res, now + getWaitingTimes[k][N]);
        return;
    }
    
    if (now >= res)
        return;

    for (int i=N-(K-k); i>0; --i){
        now += getWaitingTimes[k][i];
        N -= i;
        backTrack(k+1);
        N += i;
        now -= getWaitingTimes[k][i];
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    N = n;
    K = k;
    vector<vector<Req>> rs(k+1, vector<Req>(0));
    
    for (vector<int>& req : reqs){
        int a = req[0], b = req[1], c = req[2];
        
        rs[c].emplace_back(a, b);
    }
    
    getWaitingTimes.assign(k+1, vector<int>(n+1, 1 << 20));
    
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
    
    backTrack(1);
    
    return res;
}
    
    