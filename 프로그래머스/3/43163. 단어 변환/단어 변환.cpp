# include <string>
# include <vector>
# include <queue>
using namespace std;

int getDiff(string a, string b){
    int diff = 0;
    int n = a.size();
    for (int i=0; i<n; ++i){
        diff += (a[i] != b[i]);
    }
    
    return diff;
}

int solution(string begin, string target, vector<string> words) {
    
    int n = words.size();
    vector<vector<int>> edges(n+1, vector<int>(0));
    
    for (int j=0; j<n; ++j){
        if (getDiff(begin, words[j]) == 1){
            edges[0].push_back(j+1);
            edges[j+1].push_back(0);
        }
    }
    
    for (int i=0; i<n; ++i){
        for (int j=i+1; j<n; ++j){
            if (getDiff(words[i], words[j]) == 1){
                edges[i+1].push_back(j+1);
                edges[j+1].push_back(i+1);
            }
        }
    }
    
    queue<int> q;
    vector<int> visited(n+1, -1);
    q.push(0);
    visited[0] = 0;
    
    while (q.size()){
        int x = q.front();  q.pop();
        if (x && words[x-1] == target){
            return visited[x];
        }
        
        for (int nx : edges[x]){
            if (visited[nx] != -1)
                continue;
            
            q.push(nx);
            visited[nx] = visited[x] + 1;
        }
    }
    
    return 0;
}