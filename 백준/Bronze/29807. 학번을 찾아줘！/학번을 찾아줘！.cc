# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    int korean = 0, math = 0, english = 0, explore = 0, lang = 0;
    int* scores[] = {&korean, &math, &english, &explore, &lang};
    
    for (int i=0; i<t; i++){
        cin >> *scores[i];
    }


    int ans = 0;
    if (korean > english){
        ans += (korean - english) * 508;
    }
    else {
        ans += (english - korean) * 108;
    }

    if (math > explore){
        ans += (math - explore) * 212;
    }
    else {
        ans += (explore - math) * 305;
    }

    if (lang){
        ans += lang * 707;
    }

    cout << ans * 4763;
}