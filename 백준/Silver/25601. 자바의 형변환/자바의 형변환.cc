# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <unordered_map>
# include <unordered_set>
using namespace std;

int main(void){
    int n;  cin >> n;
    unordered_map<string, vector<string>> edges;
    for (int i=0; i<n-1; i++){
        string a, b;    cin >> a >> b;
        edges[b].push_back(a);
    }

    string a, b;    cin >> a >> b;
    queue<string> q;
    unordered_set<string> visited;
    q.push(a);  visited.insert(a);
    while (q.size()){
        string x = q.front();   q.pop();
        if (x == b){
            cout << 1;
            return 0;
        }
        for (string nx : edges[x]){
            if (visited.find(nx) != visited.end()){
                continue;
            }
            q.push(nx);
            visited.insert(nx);
        }
    }

    visited.clear();

    q.push(b);  visited.insert(b);
    while (q.size()){
        string x = q.front();   q.pop();
        if (x == a){
            cout << 1;
            return 0;
        }
        for (string nx : edges[x]){
            if (visited.find(nx) != visited.end()){
                continue;
            }
            q.push(nx);
            visited.insert(nx);
        }
    }
    cout << 0;
}