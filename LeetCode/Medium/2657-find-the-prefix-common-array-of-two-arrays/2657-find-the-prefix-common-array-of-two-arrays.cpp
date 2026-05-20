# include <vector>

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int cnt = 0;
        vector<int> res(n, 0);
        vector<int> chk(n+1, 0);

        for (int i=0; i<n; i++){
            int a = A[i], b = B[i];

            if (chk[a] < 2){
                if (chk[a]){
                    ++cnt;
                }
                chk[a] = 1;
            }
            if (chk[b] < 2){
                if (chk[b]){
                    ++cnt;
                }
                chk[b] = 1;
            }

            res[i] = cnt;
        }

        return res;
    }
};