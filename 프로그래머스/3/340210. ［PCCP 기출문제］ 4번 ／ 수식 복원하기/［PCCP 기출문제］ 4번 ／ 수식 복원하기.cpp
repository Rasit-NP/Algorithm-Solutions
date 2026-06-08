# include <set>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Expression{
private:
    string origin;
    int a, b, c;
    bool isPlus;
    bool clear;
    
    string getBase(int x, int base){
        if (x == 0){
            return "0";
        }
        string res = "";
        vector<int> vec;
        while (x){
            vec.push_back(x%base);
            x /= base;
        }

        while (vec.size()){
            res.push_back(vec.back() + '0');
            vec.pop_back();
        }
        return res;
    }
public:
    Expression(): a(0), b(0), c(0), isPlus(false), clear(false){}
    
    Expression(string& expression){
        this->origin = expression;
        int len = expression.size();
        int pmIdx;
        int eqIdx;
        
        for (int i=0; i<len; i++){
            char let = expression[i];
            if (let == '+' || let == '-'){
                isPlus = (let == '+' ? true : false);
                pmIdx = i;
            }
            else if (let == '='){
                eqIdx = i;
            }
        }
        this->a = stoi(expression.substr(0, pmIdx-1));
        this->b = stoi(expression.substr(pmIdx+2, eqIdx-pmIdx-3));
        string result = expression.substr(eqIdx+2, len-eqIdx-2);
        if (result == "X"){
            this->clear = false;
        }
        else {
            c = stoi(result);
            this->clear = true;
        }
    }
    
    int getMax(){
        int maxi = 1;
        vector<int> nums = {a, b};
        if (clear){
            nums.push_back(c);
        }
        
        for (int num : nums){
            while (num){
                maxi = max(maxi, num%10);
                num /= 10;
            }
        }
        
        return maxi;
    }
    
    int getNum(int x, int base){
        int res = 0;
        int mult = 1;
        while (x){
            res += (x%10) * mult;
            mult *= base;
            x /= 10;
        }
        
        return res;
    }
    
    bool checkBase(int base){
        if (this->clear == false){
            return true;
        }
        int A = getNum(this->a, base);
        int B = getNum(this->b, base);
        int C = getNum(this->c, base);
        
        if (isPlus){
            return (A+B == C);
        }
        else {
            return (A-B == C);
        }
    }
    
    bool isClear(){
        return this->clear;
    }
    
    string ans(vector<int>& ables){
        string res = origin;
        set<string> chk;
        string last;
        for (int able : ables){
            int A = getNum(this->a, able);
            int B = getNum(this->b, able);
            int C = (this->isPlus ? A+B : A-B);
            string trans = getBase(C, able);
            last = trans;
            chk.insert(trans);
        }
        if (chk.size() > 1){
            res.pop_back();
            res.push_back('?');
        }
        else {
            res.pop_back();
            for (char let : last){
                res.push_back(let);
            }
        }
        
        return res;
    }
};

vector<string> solution(vector<string> expressions) {
    int n = expressions.size();
    vector<Expression> exps;
    for (int i=0; i<n; i++){
        exps.emplace_back(expressions[i]);
    }
    
    int maxNum = 1;
    for (auto& exp : exps){
        maxNum = max(maxNum, exp.getMax());
    }
    
    
    vector<int> ables;
    for (int base = maxNum+1; base <= 9; base++){
        bool chk = true;
        for (auto& exp : exps){
            if (exp.isClear() == false){
                continue;
            }
            if (!exp.checkBase(base)){
                chk = false;
                break;
            }
        }
        if (chk){
            ables.push_back(base);
        }
    }
    
    vector<string> res;
    
    for (auto& exp : exps){
        if (exp.isClear() == false){
            res.push_back(exp.ans(ables));
        }
    }
    
    return res;
}