# include <string>
# include <vector>
using namespace std;

int trans(int time){
    return (time/100)*60 + time%100;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int n = schedules.size();
    
    int count = 0;
    
    for (int i=0; i<n; i++){
        int time = trans(schedules[i]);
        bool check = true;
        for (int j=0; j<7; j++){
            int today = (startday + j)%7;
            if (today == 0 || today == 6)
                continue;
            if (trans(timelogs[i][j]) > time+10){
                check = false;
                break;
            }
        }
        count += (check ? 1 : 0);
    }
    
    return count;
}