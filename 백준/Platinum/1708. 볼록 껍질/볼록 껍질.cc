# include <iostream>
# include <vector>
# include <algorithm>
# include <set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<pair<int, int>> positions;
    for (int i=0; i<n; i++){
        int x, y;   cin >> x >> y;
        positions.push_back({x, y});
    }

    sort(positions.begin(), positions.end());

    vector<pair<int, int>> lower_hull;
    for (pair<int, int> position : positions){
        int x1, y1, x2, y2;
        int x3 = position.first, y3 = position.second;
        while (true){
            if (lower_hull.size() < 2){
                break;
            }
            x1 = (lower_hull.end()-2) -> first;
            y1 = (lower_hull.end()-2) -> second;
            x2 = lower_hull.back().first;
            y2 = lower_hull.back().second;
            pair<int, int> v1 = {x2-x1, y2-y1}, v2 = {x3-x2, y3-y2};
            if ((long long)v1.first*v2.second - v1.second*v2.first <= 0){
                lower_hull.pop_back();
            }
            else {
                break;
            }
        }
        lower_hull.push_back({x3, y3});
    }

    vector<pair<int, int>> upper_hull;
    for (int i=n-1; i>=0; i--){
        int x1, y1, x2, y2;
        int x3 = positions[i].first, y3 = positions[i].second;
        while (true){
            if (upper_hull.size() < 2){
                break;
            }
            x1 = (upper_hull.end()-2) -> first;
            y1 = (upper_hull.end()-2) -> second;
            x2 = upper_hull.back().first;
            y2 = upper_hull.back().second;
            pair<int, int> v1 = {x2-x1, y2-y1}, v2 = {x3-x2, y3-y2};
            if ((long long)v1.first*v2.second - v1.second*v2.first <= 0){
                upper_hull.pop_back();
            }
            else {
                break;
            }
        }
        upper_hull.push_back({x3, y3});
    }
    set<pair<int, int>> convex_hull;
    for (pair<int, int> position : lower_hull){
        convex_hull.insert(position);
    }
    for (pair<int, int> position : upper_hull){
        convex_hull.insert(position);
    }
    cout << convex_hull.size() << '\n';
}