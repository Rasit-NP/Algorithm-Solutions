class Solution {
private:
    int getGCD(int a, int b){
        while (a % b){
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        return b;
    }
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n*n;
        int even = odd + n;

        return getGCD(even, odd);
    }
};