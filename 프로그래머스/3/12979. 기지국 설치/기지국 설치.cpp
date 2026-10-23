# include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w){
    int now = 0;
    int res = 0;
    
    for (int station : stations){
        int start = station - w;
        int end = station + w;
        
        if (now < start - 1){
            int sz = start - now - 1;
            res += (sz + 2*w) / (2*w + 1);
        }
        
        now = end;
    }
    
    if (now < n){
        int sz = n - now;
        res += (sz + 2*w) / (2*w + 1);
    }
    
    return res;
}