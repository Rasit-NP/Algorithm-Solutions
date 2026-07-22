# include <string>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

vector<int> vec;

void parse(string& s){
    int len = s.size();
    int offset = 0;
    
    while (true){
        size_t sp = s.find(' ', offset);
        if (sp == string::npos){
            vec.emplace_back(stoi(s.substr(offset, len-offset)));
            return;
        }
        else {
            vec.emplace_back(stoi(s.substr(offset, sp-offset)));
            offset = sp+1;
        }
    }
}

string solution(string s) {
    parse(s);
    
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    for (int val : vec){
        mini = min(mini, val);
        maxi = max(maxi, val);
    }
    
    string res = to_string(mini);
    res.push_back(' ');
    res.append(to_string(maxi));
    
    return res;
}