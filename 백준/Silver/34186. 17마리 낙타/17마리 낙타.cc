# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

long long cal_lcm(long long x, long long y){
    int a = max(x, y), b = min(x, y);
    if (a < b){
        swap(a, b);
    }
    int temp;
    while (a%b){
        temp = a%b;
        a = b;
        b = temp;
    }
    int gcd = b;
    long long res = (long long)x * y;
    res /= gcd;
    return res;
}

void run(){
    int n, a, b, c;     cin >> n >> a >> b >> c;
    long long lcm = cal_lcm(a, cal_lcm(b, c));
    long long son_a = lcm/a, son_b = lcm/b, son_c=lcm/c;
    long long son = son_a + son_b + son_c;
    if (lcm < son){
        cout << -1 << '\n';
    }
    else if (n%son == 0){
       cout << (lcm - son) * (n/son) << '\n'; 
    }
    else {
        cout << -1 << '\n';
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int t;  cin >> t;
    while (t--){
        run();
    }
}