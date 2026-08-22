class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1;
        int num = n;
        while (num){
            int val = num % 10;
            s += val;
            p *= val;
            num /= 10;
        }
        return n % (s+p) == 0;
    }
};