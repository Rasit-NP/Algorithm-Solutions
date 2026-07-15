class Solution {
private:
    int getGCD(int a, int b){
        if (a < b)
            swap(a, b);
        
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

        return getGCD(odd, even);
    }
};