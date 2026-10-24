# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    static vector<int> days;

    int parseDays(string day){
        int mm = stoi(day.substr(0, 2));

        int dd = stoi(day.substr(3, 2));

        return days[mm] + dd;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {   
        vector<pair<int, int>> days;

        days.emplace_back(parseDays(arriveAlice), parseDays(leaveAlice));
        days.emplace_back(parseDays(arriveBob), parseDays(leaveBob));

        sort(days.begin(), days.end());

        cout << days[1].first << ' ' << days[0].second;

        if (days[1].first > days[0].second){
            return 0;
        }
        else {
            return min(days[1].second, days[0].second) - days[1].first + 1;
        }
    }
};

vector<int> Solution::days = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};