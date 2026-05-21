# include <vector>
# include <algorithm>
# include <unordered_set>
using namespace std;

class Solution {
private:
    int getDigit(int x){
        int res = 0;
        while (x){
            ++res;
            x /= 10;
        }

        return res;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix;
        int ans = 0;
        for (int num : arr1){
            while (num){
                prefix.insert(num);
                num /= 10;
            }
        }

        for (int num : arr2){
            while (num){
                if (prefix.find(num) != prefix.end()){
                    ans = max(ans, getDigit(num));
                    break;
                }
                num /= 10;
            }
        }

        return ans;
    }
};