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
                int len = res.size();
                res.reserve(2*len);
                for (int i=0; i<len; i++){
                    res.push_back(res[i]);
                }
            }
            else if (let == '%'){
                reverse(res.begin(), res.end());
            }
        }

        return res;
    }
};