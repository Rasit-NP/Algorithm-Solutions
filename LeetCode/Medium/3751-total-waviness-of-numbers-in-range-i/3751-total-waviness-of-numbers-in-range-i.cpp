# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int count(int x){
        int res = 0;
        vector<int> vec;
        while (x){
            vec.push_back(x%10);
            x /= 10;
        }

        int n = vec.size();

        if (n < 3){
            return 0;
        }
        for (int i=1; i<n-1; i++){
            if (min(vec[i-1], vec[i+1]) > vec[i] || max(vec[i-1], vec[i+1]) < vec[i]){
                ++res;
            }
        }

        return res;
    }
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int num=num1; num<=num2; num++){
            res += count(num);
        }

        return res;
    }
};