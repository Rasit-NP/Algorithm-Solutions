# include <string>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left = 0, right = 0;
        int leftQ = 0, rightQ = 0;
        for (int i=0, len=n/2; i<len; i++){
            if (num[i] != '?'){
                left += num[i] - '0';
            }
            else {
                ++leftQ;
            }
        }
        for (int i=n/2; i<n; i++){
            if (num[i] != '?'){
                right += num[i] - '0';
            }
            else {
                ++rightQ;
            }
        }

        if (leftQ > rightQ){
            swap(leftQ, rightQ);
            swap(left, right);
        }
        rightQ -= leftQ;
        leftQ = 0;
        left -= right;

        if (rightQ == 0 && left == 0)
            return false;

        if (rightQ & 1)
            return true;

        if (left == rightQ * 9 / 2)
            return false;
        else 
            return true;
    }
};