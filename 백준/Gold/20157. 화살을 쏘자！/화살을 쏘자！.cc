# include <iostream>
# include <algorithm>
# include <unordered_map>
# define MAX 1000005
# define MAX_2 2000010
using namespace std;

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    if (a < b){
        swap(a, b);
    }
    if (b == 0){
        return a;
    }
    while (a%b){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int n;  cin >> n;
    unordered_map<long long, int> table;
    for (int i=0; i<n; i++){
        int x, y;   cin >> x >> y;
        int g = gcd(x, y);
        long long nx = x/g + MAX, ny = y/g + MAX;
        long long key = nx*MAX_2 + ny;
        table[key] += 1;
    }

    int res = 0;
    for (const auto& [key, value] : table){
        res = max(res, value);
    }

    cout << res << '\n';
}