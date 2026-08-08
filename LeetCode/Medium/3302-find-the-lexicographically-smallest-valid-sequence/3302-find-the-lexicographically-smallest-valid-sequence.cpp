# include <vector>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suf(n+1, 0);
        int j = m-1;
        for (int i=n-1; i>=0; i--){
            if (j>=0 && word1[i] == word2[j]){
                j--;
            }
            suf[i] = m - 1 - j;
        }

        vector<int> res;
        bool used = false;
        
        j=0;
        for (int i=0; i<n && j < m; i++){
            if (word1[i] == word2[j]){
                res.push_back(i);
                j++;
            }
            else if (!used){
                if (suf[i+1] >= m - (j+1)){
                    res.push_back(i);
                    used = true;
                    j++;
                }
            }
        }

        if (j == m)
            return res;
        else
            return {};
    }
};