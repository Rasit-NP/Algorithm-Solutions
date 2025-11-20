# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, tc=0;
    cin >> T;
    for (; tc<T; tc++){
        int c, v, i=0;
        cin >> c >> v;
        vector<vector<int>> table(v, vector<int>(c));
        vector<int> got1(c+1, 0);
        vector<int> got2(c+1, 0);
        priority_queue<pair<int, int>> result1;
        priority_queue<pair<int, int>> result2;
        for (; i<v; i++){
            for (int j=0; j<c; j++){
                cin >> table[i][j];
            }
            got1[table[i][0]]++;
        }
        for (i=1; i<=c; i++){
            result1.push(make_pair(got1[i], i));
        }
        if (2 * result1.top().first >= v){
            cout << result1.top().second << " 1\n";
            continue;
        }
        int a = result1.top().second;
        result1.pop();
        int b = result1.top().second;

        for (i=0; i<v; i++){
            for (int j=0; j<c; j++){
                if (table[i][j] == a || table[i][j] == b){
                    got2[table[i][j]]++;
                    break;
                }
            }
        }
        for (i=1; i<=c; i++){
            result2.push(make_pair(got2[i], i));
        }
        cout << result2.top().second << " 2\n";
    }
}