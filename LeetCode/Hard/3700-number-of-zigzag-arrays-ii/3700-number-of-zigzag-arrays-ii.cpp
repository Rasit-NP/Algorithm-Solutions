# include <vector>
using namespace std;
typedef long long llong;

class Solution {
private:
    vector<vector<int>> edges;

    vector<vector<int>> mult(vector<vector<int>>& a, vector<vector<int>>& b){
        int len = a.size();
        vector<vector<int>> res(len, vector<int>(len, 0));

        for (int i=0; i<len; i++){
            for (int j=0; j<len; j++){
                llong val = 0;
                for (int k=0; k<len; k++){
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

        vector<int> state(2*len, 1);
        vector<vector<int>> now(2*len, vector<int>(2*len, 0));
        for (int i=0; i<2*len; i++){
            now[i][i] = 1;
        }

        --n;
        for (vector<vector<int>> base = edges; n; base = square(base)){
            if (n&1){
                now = mult(now, base);
            }
            n >>= 1;
        }

        int res = 0;

        for (int i=0; i<2*len; i++){
            for (int j=0; j<2*len; j++){
                res += now[i][j];
                res %= 1'000'000'007;
            }
        }

        return res;
    }
};