# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <unordered_set>
using namespace std;

unordered_set<string> sets;
vector<bool> included;
string word;
string newWord;
int len;

void back_track(){
    if (newWord.size() == len){
        cout << newWord << '\n';
    }

    for (int i=0; i<len; i++){
        if (!included[i]){
            included[i] = true;
            newWord.push_back(word[i]);
            if (sets.find(newWord) == sets.end()){
                sets.insert(newWord);
                back_track();
            }
            newWord.pop_back();
            included[i] = false;
        }
    }
    return;
}

void run(void){
    cin >> word;
    len = word.size();
    included.assign(len, false);

    sort(word.begin(), word.end());

    newWord = "";
    back_track();
    sets.clear();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    while (n--)
        run();
}