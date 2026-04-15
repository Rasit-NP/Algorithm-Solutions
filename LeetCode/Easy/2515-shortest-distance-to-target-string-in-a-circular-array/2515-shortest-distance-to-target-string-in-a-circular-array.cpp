# include <string>
# include <vector>
# include <climits>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int sz = words.size();
        int mini = INT_MAX;
        for (int i=0; i<sz; i++){
            if (words[i] == target){
                int len = abs(startIndex - i);
                mini = min(mini, len);
                mini = min(mini, sz-len);
            }
        }

        if (mini == INT_MAX){
            return -1;
        }
        else {
            return mini;
        }
    }
};