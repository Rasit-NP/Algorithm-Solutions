class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int loss = 1;
        int n = digits.size();
        vector<int> res;
        
        for (int i=n-1; i>=0; i--){
            if (loss){
                digits[i] += 1;
                loss = 0;
            }
            if (digits[i] == 10){
                digits[i] = 0;
                loss = 1;
            }
        }
        if (loss){
            res.push_back(1);
        }
        for (int digit : digits){
            res.emplace_back(digit);
        }

        return res;
    }
};