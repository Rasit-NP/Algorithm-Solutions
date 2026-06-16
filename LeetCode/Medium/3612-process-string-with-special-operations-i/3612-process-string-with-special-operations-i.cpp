# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (char let : s){
            if (let >= 'a' && let <= 'z'){
                res.push_back(let);
            }
            else if (let == '*'){
                if (res.size()){
                    res.pop_back();
                }
            }
            else if (let == '#'){
                res += res;
            }
            else if (let == '%'){
                reverse(res.begin(), res.end());
            }
        }

        return res;
    }
};