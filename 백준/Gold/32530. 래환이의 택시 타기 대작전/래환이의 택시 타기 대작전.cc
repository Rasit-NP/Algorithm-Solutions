# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

int trans_time(string time){
    return stoi(time.substr(0, 2))*60 + stoi(time.substr(3, 2));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> times(n, 0);
    string time;
    for (int i=0; i<n; i++){
        cin >> time;
        times[i] = trans_time(time);
    }
    sort(times.begin(), times.end());
    vector<int> taxi;
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (taxi.size() == 0){
            taxi.push_back(times[i]);
        }
        else if (taxi.size() && times[i] <= taxi[0] + 20){
            taxi.push_back(times[i]);
        }
        else if (taxi.size() && times[i] > taxi[0] + 20){
            cnt++;
            taxi.clear();
            taxi.push_back(times[i]);
        }
        if (taxi.size() == 3){
            cnt++;
            taxi.clear();
        }
    }
    if (taxi.size())    cnt++;
    cout << cnt << '\n';
}