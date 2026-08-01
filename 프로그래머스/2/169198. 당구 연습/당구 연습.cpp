# include <vector>
# include <cmath>
# include <algorithm>
using namespace std;

struct Position{
    int x, y;
    static int originX, originY;
    
    Position(int x, int y): x(x), y(y){}
    Position(): Position(0, 0){}
    
    int getDistance(int x, int y) const {
        if (originX == x && x == this->x){
            if ((originY > y && y > this->y) || (originY < y && y < this->y)){
                return 1 << 30;
            }
        }
        else if (originY == y && y == this->y){
            if ((originX > x && x > this->x) || (originX < x && x < this->x)){
                return 1 << 30;
            }
        }
        else if ((originX-x)*(y-this->y) == (x-this->x)*(originY-y)){
            return 1 << 30;
        }
        return pow(this->x - x, 2) + pow(this->y - y, 2);
    }
};

int Position::originX;
int Position::originY;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> res;
    
    Position::originX = startX;
    Position::originY = startY;
    
    vector<Position> targets;
    for (int dx : {0, startX, m}){
        int nx = 2*dx - startX;
        for (int dy : {0, startY, n}){
            if (dx == startX && dy == startY)
                continue;
            int ny = 2*dy - startY;
            
            targets.emplace_back(nx, ny);
        }
    }
    
    for (const vector<int>& ball : balls){
        int x = ball[0], y = ball[1];
        int mini = 1 << 30;
        for (const Position& target : targets){
            mini = min(mini, target.getDistance(x, y));
        }
        res.emplace_back(mini);
    }
    
    return res;
}