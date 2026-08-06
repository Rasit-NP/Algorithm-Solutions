class Solution {
private:
    int getPd(int n){
        int res = 1;
        while (n){
            res *= (n%10);
            n /= 10;
        }

        return res;
    }
public:
    int smallestNumber(int n, int t) {
        for (int i=0; i<10; i++){
            int pd = getPd(n);

            if (pd%t){
                ++n;
                continue;
            }
            else
                break;
        }

        return n;
    }
};