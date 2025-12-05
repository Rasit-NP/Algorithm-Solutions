# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

int cal(int time){
    return ((time/60) + (time%60 ? 1 : 0)) * 1000;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc=1; tc<=t; tc++){
        int d, ans = 0;
        string times;
        cin >> times >> d;

        int now = stoi(times.substr(0, 2))*60 + stoi(times.substr(3, 2));
        while (d>0){
            if (now >= 1320){
                if (d < 300){
                    ans += cal(d);
                    d = 0;
                    continue;
                }
                ans += 5000;
                if (d <= 600 - (now-1320)){
                    d = 0;
                }
                else {
                    d -= 600 - (now-1320);
                    now = 480;
                }
            }
            else if (now < 480){
                if (cal(d) < 5000 + cal(d-(480-now))){
                    ans += cal(d);
                    d = 0;
                }
                else{
                    ans += 5000;
                    d -= 480 - now;
                    now = 480;
                }
            }
            else {
                if (d <= 1320-now){
                    ans += cal(d);
                    d = 0;
                }
                else {
                    if (cal(d) < cal(1320-now) + 5000){
                        ans += cal(d);
                        d = 0;
                    }
                    else {
                        ans += cal(1320-now);
                        d -= 1320 - now;
                        now = 1320;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}