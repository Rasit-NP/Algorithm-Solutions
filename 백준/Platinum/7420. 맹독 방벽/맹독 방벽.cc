# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;

int main(void){
    int n, l;   cin >> n >> l;
    vector<pair<int, int>> positions;
    for (int i=0; i<n; i++){
        int x, y;   cin >> x >> y;
        positions.push_back({x, y});
    }
    sort(positions.begin(), positions.end());

    vector<pair<int, int>> lower_hull;
    for (pair<int, int> position : positions){
        int x3 = position.first, y3 = position.second;
        if (lower_hull.size() < 2){
            lower_hull.push_back({x3, y3});
            continue;
        }
        int x1 = (lower_hull.end()-2)->first, y1 = (lower_hull.end()-2)->second;
        int x2 = lower_hull.back().first, y2 = lower_hull.back().second;
        pair<int, int> v1 = {x2-x1, y2-y1}, v2 = {x3-x2, y3-y2};
        while (lower_hull.size() >= 2 && v1.first*v2.second - v1.second*v2.first <= 0){
            lower_hull.pop_back();
            x1 = (lower_hull.end()-2)->first, y1 = (lower_hull.end()-2)->second;
            x2 = lower_hull.back().first, y2 = lower_hull.back().second;
            v1 = {x2-x1, y2-y1}, v2 = {x3-x2, y3-y2};
        }
        lower_hull.push_back({x3, y3});
    }
    
    vector<pair<int, int>> upper_hull;
    for (int i=n-1; i>=0; i--){
        pair<int, int> position = positions[i];
        int x3 = position.first, y3 = position.second;
        if (upper_hull.size() < 2){
            upper_hull.push_back({x3, y3});
            continue;
        }
        int x1 = (upper_hull.end()-2)->first, y1 = (upper_hull.end()-2)->second;
        int x2 = upper_hull.back().first, y2 = upper_hull.back().second;
        pair<int, int> v1 = {x2-x1, y2-y1}, v2 = {x3-x2, y3-y2};
        while (upper_hull.size() >= 2 && v1.first*v2.second - v1.second*v2.first <= 0){
            upper_hull.pop_back();
            x1 = (upper_hull.end()-2)->first, y1 = (upper_hull.end()-2)->second;
            x2 = upper_hull.back().first, y2 = upper_hull.back().second;
            v1 = {x2-x1, y2-y1}, v2 = {x3-x2, y3-y2};
        }
        upper_hull.push_back({x3, y3});
    }
    vector<pair<int, int>> convex_hull;
    for (pair<int, int> position : lower_hull){
        convex_hull.push_back(position);
    }
    for (pair<int, int> position : upper_hull){
        convex_hull.push_back(position);
    }
    long double sum = 0;
    for (int i=0; i<convex_hull.size()-1; i++){
        int x1 = convex_hull[i].first, y1 = convex_hull[i].second;
        int x2 = convex_hull[i+1].first, y2 = convex_hull[i+1].second;
        sum += sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }
    cout << roundl(sum + 2*M_PI*l);
}