# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());

        for (int i=0; i<n; i++){
            if (mass < asteroids[i]){
                return false;
            }
            mass += asteroids[i];
        }

        return true;
    }
};