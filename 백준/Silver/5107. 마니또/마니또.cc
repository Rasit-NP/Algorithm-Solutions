# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
# include <unordered_set>
using namespace std;

int main(void){
    int n;
    while (cin >> n){
        static int tc = 1;
        if (!n) break;
        unordered_map<string, string> edge;
        vector<string> person(n);
        for (int i=0; i<n; i++){
            string a, b;    cin >> a >> b;
            person[i] = a;
            edge[a] = b;
        }
        
        unordered_set<string> visited;
        int ans = 0;
        for (string name : person){
            string next = edge[name];
            if (visited.find(name) != visited.end()){
                continue;
            }
            visited.insert(name);
            while (name != next){
                if (visited.find(next) != visited.end()){
                    break;
                }
                next = edge[next];
            }
            if (name == next){
                ans++;
            }
        }
        cout << tc++ << ' ' << ans << endl;
    }
}