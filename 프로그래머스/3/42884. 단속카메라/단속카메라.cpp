# include <vector>
# include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int n = routes.size();
    sort(routes.begin(), routes.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });
    
    int res = 1;
    int pos = routes.front()[1];
    for (const auto& route : routes){
        int start = route[0], end = route[1];
        
        if (pos < start){
            pos = end;
            ++res;
        }
    }
    
    return res;
}