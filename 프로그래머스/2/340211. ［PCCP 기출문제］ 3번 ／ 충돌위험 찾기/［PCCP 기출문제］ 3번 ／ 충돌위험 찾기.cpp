# include <vector>
# include <map>
using namespace std;

int n;
vector<map<int, int>> count;
vector<vector<int>> positions;

void save(vector<int>& route){
    int m = route.size();
    int time = 0;
    int nowIdx = 0;
    int x = positions[route[nowIdx]][0], y = positions[route[nowIdx]][1];
    
    for (;nowIdx < m-1; nowIdx++){
        int targetX = positions[route[nowIdx+1]][0], targetY = positions[route[nowIdx+1]][1];
        while (x != targetX || y != targetY){
            count[time][x*101+y]++;
            if (x > targetX){
                x -= 1;
            }
            else if (x < targetX){
                x += 1;
            }
            else if (y > targetY){
                y -= 1;
            }
            else if (y < targetY){
                y += 1;
            }
            ++time;
        }
    }
    count[time][x*101+y]++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    n = points.size();
    positions.push_back({0, 0});
    count.assign(21000, {});
    for (int i=0; i<n; i++){
        positions.push_back({points[i][0], points[i][1]});
    }
    
    for (vector<int> route : routes){
        save(route);
    }
    
    int res = 0;
    
    for (map<int, int>& eachCount : count){
        for (const auto& [pos, cnt] : eachCount){
            if (cnt > 1){
                ++res;
            }
        }
    }
    
    return res;
}