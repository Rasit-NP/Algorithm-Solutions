# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<vector<int>> my_mat(n, vector<int>(n, 0));
    vector<vector<int>> op_mat(n, vector<int>(n, 0));
    vector<int> max_diff(n, 0);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> my_mat[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> op_mat[i][j];
        }
    }
    for (int beta=0; beta<n; beta++){
        for (int alpha=0; alpha<n; alpha++){
            max_diff[beta] = max(max_diff[beta], abs(my_mat[alpha][beta]-op_mat[alpha][beta]));
        }
    }
    int res = 0;
    for (int order = 0; order<m; order++){
        int num;    cin >> num;
        res += max_diff[num-1];
    }
    cout << res << '\n';
}