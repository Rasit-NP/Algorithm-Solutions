# include <vector>
# include <algorithm>
# include <set>
using namespace std;
typedef pair<int, int> pii;

vector<pair<int, int>> dxdy = {{-1, 0}, {-1, 1}, {0, 1},
                               {1, 1}, {1, 0}, {1, -1},
                               {0, -1}, {-1, -1}};

struct Point{
    int x, y;
    
    Point(): Point(0, 0) {}
    Point(int x, int y): x(x), y(y){}
    
    bool operator< (const Point& p) const {
        return (this->x != p.x ? this->x < p.x : this->y < p.y);
    }
    
    bool operator== (const Point& p) const {
        return (this->x == p.x && this->y == p.y);
    }
};

struct Edge{
    Point a, b;
    
    Edge(Point a, Point b){
        this->a = min(a, b);
        this->b = max(a, b);
    }
    
    bool operator< (const Edge& e) const {
        return (this->a != e.a ? this->a < e.a : this->b < e.b);
    }
    
    bool operator== (const Edge& e) const {
        return (this->a == e.a && this->b == e.b);
    }
};

Point operate(Point p, int d){
    int x = p.x, y = p.y;
    
    const auto& [dx, dy] = dxdy[d];
    
    Point res(x + dx, y + dy);
    return res;
}

int solution(vector<int> arrows) {
    int res = 0;
    set<Point> visited;
    set<Edge> passed;
    
    Point now(0, 0);
    visited.insert(now);
    
    for (int arrow : arrows){
        for (int t=0; t<2; t++){
            Point next = operate(now, arrow);
            Edge edge(now, next);

            if (visited.find(next) != visited.end()){
                if (passed.find(edge) == passed.end()){
                    passed.insert(edge);
                    ++res;
                }
            }
            else {
                visited.insert(next);
                passed.insert(edge);
            }
            now = move(next);
        }
    }
    
    return res;
}