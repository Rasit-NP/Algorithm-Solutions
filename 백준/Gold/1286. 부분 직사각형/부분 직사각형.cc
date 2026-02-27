# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<string> table(2*n, string(2*m, ' '));
    vector<long long> count(26, 0);
    for (int i=0; i<n; i++){
        string word;    cin >> word;
        for (int j=0; j<m; j++){
            table[i][j] = word[j];
            table[i][j+m] = word[j];
            table[i+n][j] = word[j];
            table[i+n][j+m] = word[j];
        }
    }
    
    for (int i=0; i<2*n; i++){
        for (int j=0; j<2*m; j++){
            count[table[i][j]-'A'] += (i+1)*(j+1) * (2*n - i)*(2*m - j);
        }
    }

    for (auto& v : count){
        cout << v << '\n';
    }
}