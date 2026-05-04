# include <vector>
using namespace std;

vector<int> match = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

bool check(int x){
    int a = x;
    vector<int> digits;
    int len;
    while (a){
        digits.push_back(a%10);
        a /= 10;
    }

    len = digits.size();

    int num = 0;
    for (int i=0, digit = 1; i<len; i++, digit *= 10){
        int now = digits[i];
        if (match[now] == -1){
            return false;
        }
        num += match[now] * digit;
    }

    if (num == x){
        return false;
    }
    else {
        return true;
    }
}

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i=1; i<=n; i++){
            if (check(i)){
                ++count;
            }
        }

        return count;
    }
};