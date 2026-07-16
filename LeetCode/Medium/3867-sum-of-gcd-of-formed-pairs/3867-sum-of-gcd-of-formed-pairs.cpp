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
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int len = n/2;
        int nowMax = 0;
        vector<int> prefixGcd;
        prefixGcd.reserve(n);

        for (int num : nums){
            nowMax = max(nowMax, num);
            prefixGcd.emplace_back(getGCD(nowMax, num));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long res = 0;
        for (int i=0; i<len; i++){
            res += getGCD(prefixGcd[i], prefixGcd[n-i-1]);
        }

        return res;
    }
};