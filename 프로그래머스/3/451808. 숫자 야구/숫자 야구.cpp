# include <string>
# include <vector>
# include <map>
# include <set>
# include <algorithm>
using namespace std;
typedef pair<int, int> pi;

extern string submit(int);

set<int> isAble;

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
    return true;
}

int solution(int n) {

    for (int num=1234; num<=9876; ++num){
        if (check(num)){
            isAble.insert(num);
        }
    }

    pi beforeResult = convert(submit(1234));
    int beforeNum = 1234;
    
    for (int cnt=1; cnt <= 6; cnt++){
        int maxVal = 3024;
        int nextNum;
        vector<int> candidates;
        
        for (int num : isAble){
            pi ret = cal(beforeNum, num);
            if (ret.first != beforeResult.first || ret.second != beforeResult.second){
                candidates.push_back(num);
            }
        }
        
        for (int cand : candidates){
            isAble.erase(cand);
        }
        
        if (isAble.size() == 1){
            return *isAble.begin();
        }

        for (int num : isAble){
            map<pi, int> cnt;
            int worstVal = 0;
            for (int ans : isAble){
                cnt[cal(num, ans)] += 1;
            }
            for (const auto& [key, val] : cnt){
                worstVal = max(worstVal, val);
            }

            if (worstVal < maxVal){
                maxVal = worstVal;
                nextNum = num;
            }
        }
        beforeNum = nextNum;
        beforeResult = convert(submit(nextNum));
        if (beforeResult.first == 4 && beforeResult.second == 0){
            return nextNum;
        }
    }
    return 0;
}