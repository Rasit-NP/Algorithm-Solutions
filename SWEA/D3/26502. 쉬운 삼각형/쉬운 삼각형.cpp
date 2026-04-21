# include <iostream>
# include <vector>
# include <cmath>
# include <algorithm>
using namespace std;

struct Position{
    int x, y;

    Position(int x, int y) : x(x), y(y) {}
};

int area(Position& a, Position& b, Position& c){
    int x1 = a.x, y1 = a.y;
    int x2 = b.x, y2 = b.y;
    int x3 = c.x, y3 = c.y;

    return abs((x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1));
}

bool check(Position& a, Position& b, Position& c){
    if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y)){
        return true;
    }
    else if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y)){
        return true;
    }
    else if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y)){
        return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    
    while (t--){
        int n;  cin >> n;
        int ans = 0;

        vector<Position> positions;
        for (int i=0; i<n; i++){
            int x, y;   cin >> x >> y;
            positions.emplace_back(x, y);
        }

        for (int i=0; i<n; i++){
            Position& a = positions[i];
            for (int j=i+1; j<n; j++){
                Position& b = positions[j];
                for (int k=j+1; k<n; k++){
                    Position& c = positions[k];
                    if (check(a, b, c)){
                        ans = max(ans, area(a, b, c));
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}