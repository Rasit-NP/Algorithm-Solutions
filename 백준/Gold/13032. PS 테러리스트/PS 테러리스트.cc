# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct Bomb{
    int x, p;

    Bomb(int& x, int& p){
        this -> x = x;
        this -> p = p;
    }

    bool operator<(const Bomb& bomb) const {
        if (this->x < bomb.x){
            return true;
        }
        else{
            return false;
        }
    }
};

vector<int> dp;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<Bomb> bombs;
    bombs.reserve(n);
    for (int i=0; i<n; ++i){
        int x, p;   cin >> x >> p;
        bombs.emplace_back(x, p);
    }

    sort(bombs.begin(), bombs.end());

    int nextBombIdx = 0;
    int maxPosition = bombs[n-1].x;
    dp.assign(maxPosition+1, 0);

    if (bombs[nextBombIdx].x == 0){
        dp[0] = 1;
        ++nextBombIdx;
    }

    for (int i=1; i<=maxPosition; ++i){
        if (i == bombs[nextBombIdx].x){
            if (i-bombs[nextBombIdx].p - 1 < 0){
                dp[i] = 1;
            }
            else {
                dp[i] = dp[i-bombs[nextBombIdx].p - 1] + 1;
            }
            ++nextBombIdx;
        }
        else {
            dp[i] = dp[i-1];
        }
    }

    int maxi = 0;
    for (int& val : dp){
        maxi = max(maxi, val);
    }

    cout << n-maxi;
}