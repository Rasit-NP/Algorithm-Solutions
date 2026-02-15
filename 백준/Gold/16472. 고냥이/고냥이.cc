# include <iostream>
# include <unordered_map>
# include <string>
# include <algorithm>
using namespace std;

int main(void){
    int n;          cin >> n;
    string word;    cin >> word;

    int head = 0, tail = 0;
    int maximum = 1;
    unordered_map<char, int> map;
    for (int i=97; i<97+26; i++){
        map[i] = 0;
    }
    map[word[head]]++;
    int cnt = 1;
    while (head < word.length() && tail < word.length()){
        if (cnt <= n){
            maximum = max(maximum, head-tail+1);
            head++;
            char let = word[head];
            if (!map[let]){
                cnt++;
            }
            map[let]++;
        }
        else {
            char let = word[tail];
            map[let]--;
            if (!map[let]){
                cnt--;
            }
            tail++;
        }
    }
    cout << maximum;
}