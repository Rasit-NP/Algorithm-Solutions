# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

int n;
vector<int> isPrime;
vector<int> isSang;

int trans(int x){
    int res = 0;
    while (x){
        res += (x%10) * (x%10);
        x /= 10;
    }
    return res;
}

int checkSang(int x, unordered_set<int>& sets){
    if (isSang[x] != 0){
        return isSang[x];
    }
    else {
        int nx = trans(x);
        sets.insert(x);
        if (sets.find(nx) != sets.end()){
            isSang[x] = -1;
        }
        else {
            isSang[x] = checkSang(nx, sets);
        }
        return isSang[x];
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    vector<int> res;

    cin >> n;
    isPrime.assign(1000001, 1);
    isSang.assign(1000001, 0);

    isPrime[0] = 0;
    isPrime[1] = 0;
    isSang[1] = 1;

    for (int i=2; i<=n; i++){
        if (isPrime[i]){
            unordered_set<int> sets;
            isSang[i] = checkSang(i, sets);
            for (int ni = 2*i; ni<=n; ni += i){
                isPrime[ni] = 0;
            }
            if (isSang[i] == 1){
                res.push_back(i);
            }
        }
    }

    for (int i=0; i<res.size(); i++){
        if (i)
            cout << '\n';
        cout << res[i];
    }
}