# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26, 0), lower(26, 0);
        int res = 0;
        for (char let : word){
            if (let > 96){
                int idx = let - 'a';
                if (upper[idx] > 0 && lower[idx] == 0){
                    ++res;
                }
                ++lower[idx];
            }
            else {
                int idx = let - 'A';
                if (lower[idx] > 0 && upper[idx] == 0){
                    ++res;
                }
                ++upper[idx];
            }
        }

        return res;
    }
};