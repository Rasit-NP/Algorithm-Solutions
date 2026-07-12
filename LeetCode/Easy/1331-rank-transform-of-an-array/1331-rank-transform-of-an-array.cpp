# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> scores = arr;
        vector<int> res(n, 0);
        
        sort(scores.begin(), scores.end());
        unordered_map<int, int> getRank;
        int rank = 1;
        for (int score : scores){
            if (getRank.find(score) != getRank.end()){
                continue;
            }
            getRank[score] = rank++;
        }

        for (int i=0; i<n; i++){
            int score = arr[i];
            res[i] = getRank[score];
        }

        return res;
    }
};