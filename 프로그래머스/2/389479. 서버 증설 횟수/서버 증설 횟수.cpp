# include <vector>
# include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int res = 0;
    queue<pair<int, int>> q;
    int addedServer = 0;
    for (int time=0; time<24; time++){
        int player = players[time];
        while (q.size() && q.front().first <= time){
            addedServer -= q.front().second;
            q.pop();
        }
        if (player > addedServer * m){
            int dt = player/m;
            res += dt - addedServer;
            q.push({time + k, dt - addedServer});
            addedServer = dt;
        }
    }
    
    return res;
}