# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> scores(5, 0);
vector<int> maximum = {15, 7, 5, 3, 3};
int sum_a = 0;
int sum_ia = 0;
int cost = 0;

int ans = 0;

void backtrack(int len){
    if (len == 5){
        if (sum_a <= 3 && sum_ia <= 10){
            ans = max(ans, cost);
        }
        else if (sum_a>=4 && sum_ia <= 15){
            ans = max(ans, cost);
        }
        return;
    }
    for (int i=0; i<=maximum[len]; i++){
        sum_a += i;
        sum_ia += i*(len+1);
        cost += i*scores[len];
        backtrack(len+1);
        cost -= i*scores[len];
        sum_ia -= i*(len+1);
        sum_a -= i;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    for (int i=0; i<5; i++){
        cin >> scores[i];
    }
    
    backtrack(0);
    cout << ans << '\n';
}