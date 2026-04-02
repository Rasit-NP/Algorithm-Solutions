# include <iostream>
# include <vector>
# include <string>
# include <unordered_set>
# include <algorithm>
using namespace std;

int maxNum;
int inputSize;
string input;
vector<int> ans;
unordered_set<int> sets;

bool backtrack(int i){
    if (i == inputSize){
        for (int i=0; i<ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size()-1];
        }
        return true;
    }
    for (int len=1; len<=min(2, inputSize-i); len++){
        int num = stoi(input.substr(i, len));
        if (num <= maxNum && sets.find(num) == sets.end()){
            sets.insert(num);
            ans.push_back(num);
            if (backtrack(i + len)){
                return true;
            }
            sets.erase(num);
            ans.pop_back();
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> input;
    inputSize = input.size();

    if (inputSize < 10){
        maxNum = input.size();
    }
    else {
        maxNum = 9 + (inputSize-9)/2;
    }

    backtrack(0);
}