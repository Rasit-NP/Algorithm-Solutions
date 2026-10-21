# include <string>
# include <algorithm>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string str = s;
        sort(str.begin(), str.end());
        char begin = str.front(), last = str.back();

        for (int i=1; i<n; ++i){
            if (s[i] < s[i-1]){
                break;
            }
            if (i == n-1){
                return 0;
            }
        }

        if (n == 1){
            return 0;
        }
        else if (n == 2){
            return -1;
        }
        
        unordered_set<int> sets;

        for (int i=1; i<n-1; ++i){
            sets.insert(s[i]);
        }

        if (s.front() == begin || s.back() == last){
            return 1;
        }
        else if (sets.find(begin) == sets.end() && sets.find(last) == sets.end()){
            return 3;
        }
        else {
            return 2;
        }
    }
};