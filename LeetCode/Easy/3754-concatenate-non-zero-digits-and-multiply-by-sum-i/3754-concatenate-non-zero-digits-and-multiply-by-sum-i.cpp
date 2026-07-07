using namespace std;
typedef long long ll;

class Solution {
public:
    ll sumAndMultiply(int n) {
        int digit = 1;
        int x = 0, sum = 0;
        while (n){
            int val = n % 10;
            if (val != 0){
                x += val*digit;
                sum += val;
                digit *= 10;
            }
            n /= 10;
        }
        return (ll)x * sum;
    }
};