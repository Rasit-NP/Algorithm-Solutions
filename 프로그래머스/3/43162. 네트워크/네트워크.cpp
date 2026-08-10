# include <vector>
# include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int res = 0;
    vector<int> visited(n, 0);
    
    for (int i=0; i<n; i++){
        if (!visited[i]){
            queue<int> q;
            q.push(i);
            
            while (q.size()){
                int x = q.front();  q.pop();
                for (int nx=0; nx<n; nx++){
                    if (computers[x][nx] && !visited[nx]){
                        visited[nx] = 1;
                        q.push(nx);
                    }
                }
            }
            ++res;
        }
    }
    
    return res;
}