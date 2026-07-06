# include <string>
# include <vector>
# include <map>
using namespace std;
typedef pair<int, int> pi;

extern string submit(int);

map<int, pi> rec;

pi convert(string ret){
    pi res;
    res.first = ret[0] - '0';
    res.second = ret[3] - '0';
    
    return res;
}

pi cal(int xx, int aans){
    string x = to_string(xx);
    string ans = to_string(aans);
    
    pi res = {0, 0};
    
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (x[i] == ans[j]){
                if (i == j){
                    ++res.first;
                }
                else {
                    ++res.second;
                }
            }
        }
    }
    
    return res;
}

bool check(int target){
    {
        int x = target;
        vector<int> cnt(10, 0);
        while (x){
            ++cnt[x%10];
            x /= 10;
        }
        for (int num : cnt){
            if (num > 1){
                return false;
            }
        }
    }{
        string x = to_string(target);
        if (x[0] == '0' || x[1] == '0' || x[2] == '0' || x[3] == '0')
            return false;
    }
    
    for (const auto& [x, mem] : rec){
        pi ret = cal(x, target);
        if (ret.first != mem.first || ret.second != mem.second){
            return false;
        }
    }
    
    return true;
}

int solution(int n) {
    int cnt = 0;
    for(int i = 1000; i <= 9999; i++){
        pi ret;
        if (!check(i)){
            continue;
        }
        if (++cnt <= n){
            ret = convert(submit(i));
        }
        else {
            return i;
        }
        if (ret.first == 4 && ret.second == 0){
            return i;
        }
        else {
            rec.insert({i, ret});
        }
    }
    return 0;
}