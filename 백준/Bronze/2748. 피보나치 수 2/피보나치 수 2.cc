# include <iostream>
using namespace std;

int main(void){
    long long x = 0, nx = 1;
    int n;  cin >> n;
    for (int i=2; i<=n; i++){
        long long tmp = x + nx;
        x = nx, nx = tmp;
    }
    cout << nx;
}