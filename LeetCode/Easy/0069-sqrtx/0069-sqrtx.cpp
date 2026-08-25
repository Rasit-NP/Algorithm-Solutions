using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = 1<<31 - 1;
        while (r-l > 1){
            long long mid = (l+r)/2;
            if (mid*mid <= x){
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};