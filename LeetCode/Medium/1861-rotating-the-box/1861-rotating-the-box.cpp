using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();

        vector<vector<char>> ansBox(m, vector<char>(n, '.'));

        for (int i=0; i<n; i++){
            int count = 0;
            for (int j=0; j<m; j++){
                if (boxGrid[i][j] == '#'){
                    ++count;
                    boxGrid[i][j] = '.';
                }
                else if (boxGrid[i][j] == '*'){
                    for (int k=1; k<=count; k++){
                        boxGrid[i][j-k] = '#';
                    }
                    count = 0;
                }
            }
            for (int k=1; k<=count; k++){
                boxGrid[i][m-k] = '#';
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                ansBox[j][i] = boxGrid[n-i-1][j];
            }
        }

        return ansBox;
    }
};