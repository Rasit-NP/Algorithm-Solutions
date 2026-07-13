# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
private:
    int low, high;
    vector<int> res;

    void backtrack(string x){
        if (x.empty()){
            for (char i='1'; i<='9'; i++){
                x.push_back(i);
                backtrack(x);
                x.pop_back();
            }
            return;
        }
        int val = stoi(x);
        if (val > high){
            return;
        }
        if (val >= low){
            res.push_back(val);
        }
        if (x.back() < '9'){
            x.push_back(x.back()+1);
            backtrack(x);
            x.pop_back();
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        this->low = low;
        this->high = high;

        backtrack("");

        sort(res.begin(), res.end());

        return res;
    }
};