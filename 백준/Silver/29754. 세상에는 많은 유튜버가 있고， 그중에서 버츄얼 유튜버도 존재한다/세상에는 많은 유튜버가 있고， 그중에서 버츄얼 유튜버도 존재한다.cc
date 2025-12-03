# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
# include <algorithm>
using namespace std;

int trans(string time){
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return hh*60 + mm;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, day;
    string name, time_start, time_end;
    unordered_map<string, vector<pair<int, int>>> data;
    vector<string> ans;
    cin >> n >> m;
    vector<pair<int, int>> blank(m/7, {0, 0});
    for (int i=0; i<n; i++){
        cin >> name >> day >> time_start >> time_end;
        day--;
        int time = trans(time_end)-trans(time_start);
        if (data.find(name) != data.end()){
            data[name][day/7].first++;
            data[name][day/7].second += time;
        }
        else {
            data.insert(make_pair(name, blank));
            data[name][day/7].first = 1;
            data[name][day/7].second += time;
        }
    }
    for (auto elem : data){
        string name = elem.first;
        vector<pair<int, int>> table = elem.second;
        bool check = true;
        for (int i=0; i<m/7; i++){
            if (table[i].first < 5 || table[i].second < 3600){
                check = false;
                break;
            }
        }
        if (check){
            ans.push_back(name);
        }
    }
    if (ans.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (string name : ans){
        cout << name << endl;
    }
    return 0;
}