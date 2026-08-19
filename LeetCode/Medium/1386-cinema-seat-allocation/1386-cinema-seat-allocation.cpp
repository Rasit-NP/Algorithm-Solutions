# include <map>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int get(vector<int>& seats){
        vector<vector<int>> range = {{4, 5, 6, 7}, {2, 3, 4, 5}, {6, 7, 8, 9}};
        bool chk[3] = {true, true, true};

        for (int i=0; i<3; i++){
            for (int x : range[i]){
                if (seats[x]){
                    chk[i] = false;
                    break;
                }
            }
        }

        if (chk[1] && chk[2])
            return 2;
        else if (chk[0] || chk[1] || chk[2])
            return 1;
        else
            return 0;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> reservedRow;

        for (const auto& seat : reservedSeats){
            int r = seat[0], c = seat[1];

            reservedRow[r].emplace_back(c);
        }

        int res = 0;

        for (const auto& [row, columns] : reservedRow){
            vector<int> reserved(11, 0);
            for (int c : columns){
                reserved[c] = 1;
            }

            res += get(reserved);
        }

        return res + (n - reservedRow.size()) * 2;
    }
};