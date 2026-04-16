# include <iostream>
# include <string>
using namespace std;

int sz;

bool checkFirst(string word){
    if (word.size() < 4)
        return false;
    if (word[0] == '0' || word[1] == '1' || word[2] == '1'){
        return false;
    }
    int sz = word.size();
    int switchCount = 0;
    for (int i=3; i<sz; i++){
        if (word[i] != word[i-1]){
            ++switchCount;
        }
    }
    if (switchCount == 1){
        return true;
    }
    else {
        return false;
    }
}

bool checkSecond(string word){
    if (word == "01"){
        return true;
    }
    else {
        return false;
    }
}

bool check(string& word, int idx){
    if (sz == idx){
        return true;
    }
    bool res=false;
    if (sz - idx < 2)
        return res;
    if (checkSecond(word.substr(idx, 2))){
        res = check(word, idx+2);
    }
    if (res)
        return res;
    for (int len=4; len<=sz-idx; len++){
        if (checkFirst(word.substr(idx, len))){
            res = check(word, idx+len);
        }
        if (res)
            return res;
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string word;    cin >> word;
    sz = word.size();

    if (check(word, 0)){
        cout << "SUBMARINE";
    }
    else {
        cout << "NOISE";
    }
}