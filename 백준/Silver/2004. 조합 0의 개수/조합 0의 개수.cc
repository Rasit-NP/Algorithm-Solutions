# include <iostream>
# include <vector>
using namespace std;

long long Legendre(int x, int p){
    long long prime = p;
    long long count = 0;
    while (prime <= x){
        count += x/prime;
        prime *= p;
    }
    return count;
}

pair<long long, long long> count(int n){
    return {Legendre(n, 2), Legendre(n, 5)};
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    auto countN=count(n), countM=count(m), countN_M=count(n-m);
    pair<long long, long long> res = {countN.first-countM.first-countN_M.first, countN.second-countM.second-countN_M.second};

    cout << min(res.first, res.second);
}