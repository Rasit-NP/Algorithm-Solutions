# include <vector>
# include <deque>
# include <iostream>
using namespace std;

vector<int> solution(int n, int m, int h, int w, vector<vector<int>> drops) {
    int len = drops.size();
    vector<vector<int>> table(n, vector<int>(m, len+1));
    
    for (int i=0; i<len; i++){
        vector<int>& drop = drops[i];
        table[drop[0]][drop[1]] = i+1;
    }

    vector<vector<int>> rowMin(n, vector<int>(m-w+1, 0));
    for (int i=0; i<n; i++){
        deque<int> dq;
        for (int j=0; j<w-1; j++){
            int val = table[i][j];
            if (j == 0 || val >= dq.back()){
                dq.push_back(val);
            }
        }
        
        for (int j=w-1; j<m; j++){
            int val = table[i][j];
            if (j != 0 || (dq.size() && val >= dq.back())){
                dq.push_back(val);
            }
            rowMin[i][j-w+1] = dq.front();
            if (dq.size() && dq.front() == table[i][j-w+1]){
                dq.pop_front();
            }
        }
    }
    
    vector<vector<int>> finMin(n-h+1, vector<int>(m-w+1, 0));
    for (int j=0; j<m-w+1; j++){
        deque<int> dq;
        for (int i=0; i<h-1; i++){
            int val = table[i][j];
            if (i == 0 || val >= dq.back()){
                dq.push_back(val);
            }
        }
        
        for (int i=h-1; i<n; i++){
            int val = table[i][j];
            if (i != 0 || (dq.size() && val >= dq.back())){
                dq.push_back(val);
            }
            finMin[i-h+1][j] = dq.front();
            if (dq.size() && dq.front() == table[i-h+1][j]){
                dq.pop_front();
            }
        }
    }
    
    int res = 1'000'000;
    vector<int> ans(2, 0);
    for (int i=0; i<n-h+1; i++){
        for (int j=0; j<m-w+1; j++){
            if (finMin[i][j] < res){
                res = finMin[i][j];
                ans = {i, j};
            }
        }
    }
    
    cout << res;
    
    return ans;
}