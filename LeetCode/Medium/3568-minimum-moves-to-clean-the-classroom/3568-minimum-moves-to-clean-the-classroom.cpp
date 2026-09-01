# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> dxdy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Position{
    int x, y;

    Position() : Position(0, 0){}
    Position(int x, int y): x(x), y(y){}

    void input(int x, int y){
        this->x = x;
        this->y = y;
    }

    int flatten(){
        return x*m + y;
    }

    bool isOut(){
        return min(x, y) < 0 || x >= n || y >= m;
    }

    char getChar(vector<string>& classroom){
        return classroom[x][y];
    }
};

struct Data{
    Position p;
    int mask;
    int moved;
    int energy;
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int initEnergy) {
        n = classroom.size();
        m = classroom[0].size();
        Position start;
        vector<Position> litters;
        litters.reserve(10);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                char c = classroom[i][j];
                if (c == 'S'){
                    start.input(i, j);
                }
                else if (c == 'L'){
                    classroom[i][j] = '0' + litters.size();
                    litters.emplace_back(i, j);
                }
            }
        }

        int fullMask = (1 << litters.size()) - 1;

        vector<vector<int>> visited(1 << litters.size(), vector<int>(n*m, -1));

        queue<Data> q;
        q.push({start, 0, 0, initEnergy});
        visited[0][start.flatten()] = initEnergy;

        while (q.size()){
            Data cur = q.front();   q.pop();
            Position now = cur.p;
            int x = now.x, y = now.y;
            int mask = cur.mask;
            int t = cur.moved;
            int energy = cur.energy;

            if (mask == fullMask){
                return t;
            }

            if (energy < visited[mask][now.flatten()])
                continue;

            for (auto [dx, dy] : dxdy){
                Position next = {x+dx, y+dy};
                if (next.isOut())
                    continue;

                int newMask = mask;
                int newEnergy = energy - 1;

                if (newEnergy < 0)
                    continue;

                char c = next.getChar(classroom);
                if (c == 'X')
                    continue;
                if (c >= '0' && c <= '9')
                    newMask = mask | (1 << (c-'0'));
                if (c == 'R')
                    newEnergy = initEnergy;

                if (visited[newMask][next.flatten()] < newEnergy){
                    visited[newMask][next.flatten()] = newEnergy;
                    q.push({next, newMask, t+1, newEnergy});
                }
            }
        }

        return -1;
    }
};