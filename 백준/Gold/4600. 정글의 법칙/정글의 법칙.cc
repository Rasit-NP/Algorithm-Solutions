# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int b, p;
vector<pair<int, int>> bridges_data;
vector<pair<int, int>> bridges;
vector<int> islands;

bool init(void){
    cin >> b >> p;
    if (b == 0 && p == 0)   return false;
    b *= -1;
    bridges_data.assign(b, {0, 0}); // 최대 인원, 필요 시간
    bridges.assign(b, {0, 0});      // 현재 인원, 남은 시간
    islands.assign(b+1, 0);
    islands[0] = p;

    for (int i=0; i<b; i++){
        int c, t;   cin >> c >> t;
        bridges_data[i] = {c, t};
    }
    return true;
}

void solution(void){
    int next_time = 0, now_time = 0;

    while (islands[b] != p){
        int temp_next_time = 1 << 30;
        for (int i=0; i<b; i++){
            if (next_time == 0){
                if (bridges[i].first == 0 && islands[i] != 0){
                    bridges[i] = {min(islands[i], bridges_data[i].first), bridges_data[i].second};
                    islands[i] -= bridges[i].first;
                }
                if (bridges[i].second)
                    temp_next_time = min(temp_next_time, bridges[i].second);
            }
            else {
                if (bridges[i].first != 0){
                    bridges[i].second -= next_time;
                    if (bridges[i].second == 0){
                        islands[i+1] += bridges[i].first;
                        bridges[i].first = 0;
                        temp_next_time = 0;
                    }
                }
            }
        }
        now_time += next_time;
        next_time = temp_next_time;
    }
    cout << now_time << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    while (init()){
        solution();
    }
}