# include <iostream>
# include <string>
# include <vector>
using namespace std;

void print(string word, int cnt){
    int first = 0;
    int len = word.size();
    if (cnt == len){
        cout << word;
        return;
    }
    for (int i=0; i<len; i++){
        char& let = word[i];
        if (let < word[first]){
            first = i;
        }
    }
    if (cnt == 1){
        cout << word[first];
    }
    else if (cnt > len-first){
        print(word.substr(0, first), cnt-len+first);
        cout << word[first];
        print(word.substr(first + 1, len-first-1), len-first-1);
    }
    else {
        cout << word[first];
        print(word.substr(first + 1, len-first-1), cnt-1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string word;    cin >> word;
    for (int i=1; i<=word.size(); i++){
        print(word, i);
        cout << '\n';
    }
}