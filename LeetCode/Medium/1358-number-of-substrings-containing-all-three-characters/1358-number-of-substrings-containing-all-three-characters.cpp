# include <string>
# include <queue>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    queue<int> q[3];
public:
    int numberOfSubstrings(string s) {
        n = s.size();

        for(int i=0; i<n; i++){
            char let = s[i];

            q[let-'a'].push(i);
        }

        int res = 0;

        while (q[0].size() && q[1].size() && q[2].size()){
            sort(q, q+3);
            int first = q[0].front();   q[0].pop();
            int last = max(q[1].front(), q[2].front());

            res += n-last;
        }

        return res;
    }
};