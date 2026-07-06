# include <string>
# include <vector>
# include <map>
using namespace std;
typedef pair<int, int> pi;

extern string submit(int);

vector<int> isAble;
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
    isAble.assign(10000, 1);

    for (int num=1234; num<=9876; ++num){
        isAble[num] = check(num);
    }
    
    while (n--){
        int maxVal = 0;
        int nextNum;
        vector<int> candidates;
        candidates.reserve(3024);
        for (int num=1234; num<=9876; ++num){
            if (isAble[num] == 0){
                continue;
            }
            if (!check(num)){
                isAble[num] = 0;
                continue;
            }
            candidates.push_back(num);
        }

        for (int num : candidates){
            map<pi, int> cnt;
            for (int ans : candidates){
                cnt[cal(num, ans)] += 1;
            }
            for (const auto& [key, val] : cnt){
                if (val > maxVal){
                    nextNum = num;
                }
            }
        }

        pi ret = convert(submit(nextNum));
        if (ret.first == 4 && ret.second == 0){
            return nextNum;
        }

        rec.insert({nextNum, ret});
    }
    for (int num=1234; num<=9876; ++num){
        if (isAble[num]){
            return num;
        }
    }
    return 0;
}