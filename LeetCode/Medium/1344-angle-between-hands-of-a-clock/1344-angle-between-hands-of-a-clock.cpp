using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double hourAngle = 0;
        double minuteAngle = 0;

        hourAngle += 30 * hour;
        minuteAngle += 6 * minutes;

        hourAngle += (double)minutes/2;

        double res = hourAngle - minuteAngle;
        if (res < 0){
            res *= -1;
        }
        if (res > 180){
            res = 360 - res;
        }

        return res;
    }
};