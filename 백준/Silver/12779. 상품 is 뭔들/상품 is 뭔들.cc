# include <iostream>
# include <cmath>
using namespace std;

long long gcd(long long a, long long b){
    while(a%b){
        long long tmp = a%b;
        a = b, b = tmp;
    }
    return b;
}

int main(void){
    long double a, b;     cin >> a >> b;

    long long ra = (long long)sqrtl(a), rb = (long long)sqrtl(b);

    long long son = rb-ra, mom = b-a;
    if (son == 0){
        cout << 0;
        return 0;
    }    
    long long g = gcd(mom, son);
    cout << son/g << '/' << mom/g;
    return 0;
}