# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int l = 0, r = n-1;
        int cnt = 0;

        while (r>=l){
            if (l == r){
                ++cnt;
                break;
            }
            else if (people[r] + people[l] > limit){
                ++cnt;
                --r;
            }
            else {
                ++cnt;
                ++l;
                --r;
            }
        }

        return cnt;
    }
};