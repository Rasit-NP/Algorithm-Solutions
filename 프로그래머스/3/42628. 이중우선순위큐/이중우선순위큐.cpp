# include <string>
# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq_M, pq_m;
    unordered_map<int, int> cnt;
    
    for (string oper : operations){
        int v = stoi(oper.substr(2, oper.size()-2));
        switch (oper[0]){
            case 'I':
                pq_M.push(v);
                pq_m.push(-v);
                ++cnt[v];
                break;
            case 'D':
                if (v == 1){
                    while (pq_M.size()){
                        int val = pq_M.top();   pq_M.pop();
                        if (cnt[val]){
                            --cnt[val];
                            break;
                        }
                    }
                }  
                else {
                    while (pq_m.size()){
                        int val = -pq_m.top();   pq_m.pop();
                        if (cnt[val]){
                            --cnt[val];
                            break;
                        }
                    }
                }
        }
    }
    
    int m = 0, M = 0;
    while (pq_m.size()){
        int val = -pq_m.top();   pq_m.pop();
        if (cnt[val]){
            m = val;
            break;
        }
    }
    while (pq_M.size()){
        int val = pq_M.top();   pq_M.pop();
        if (cnt[val]){
            M = val;
            break;
        }
    }
    return {M, m};
}