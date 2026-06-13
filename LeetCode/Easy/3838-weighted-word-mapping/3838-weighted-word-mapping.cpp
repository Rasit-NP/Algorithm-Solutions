# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        res.reserve(words.size());
        for (string& word : words){
            int weight = 0;
            for (char let : word){
                weight += weights[let-'a'];
            }
            weight %= 26;
            weight = 25-weight;
            res.push_back(weight+'a');
        }

        return res;
    }
};