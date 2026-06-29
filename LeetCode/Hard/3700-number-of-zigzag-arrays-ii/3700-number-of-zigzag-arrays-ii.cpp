# include <vector>
using namespace std;
typedef long long llong;

class Solution {
private:
    vector<vector<int>> edges;

    vector<vector<int>> mult(vector<vector<int>>& a, vector<vector<int>>& b){
        int n = a.size();
        int m = b[0].size();
        int l = b.size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                llong val = 0;
                for (int k=0; k<l; k++){
                    val += (llong)a[i][k] * b[k][j];
                    val %= 1'000'000'007;
                }
                res[i][j] = (int)val;
            }
        }

        return res;
    }

    vector<vector<int>> square(vector<vector<int>>& mat){
        return mult(mat, mat);
    }
public:
    int zigZagArrays(int n, int l, int r) {
        int len = r-l+1;
        edges.assign(2*len, vector<int>(2*len, 0));

        for (int i=0; i<len; ++i){
            for (int j=0; j<len; ++j){
                if (i > j){
                    edges[i][j+len] = 1;
                }
                else if (i < j){
                    edges[i+len][j] = 1;
                }
            }
        }

        vector<vector<int>> state(2*len, vector<int>(1, 1));
        vector<vector<int>> now(2*len, vector<int>(2*len, 0));
        for (int i=0; i<2*len; i++){
            now[i][i] = 1;
        }

        --n;
        for (vector<vector<int>> base = edges; n; base = square(base)){
            if (n&1){
                state = mult(base, state);
            }
            n >>= 1;
        }

        int res = 0;

        for (int i=0; i<2*len; i++){
            res += state[i][0];
            res %= 1'000'000'007;
        }

        return res;
    }
};