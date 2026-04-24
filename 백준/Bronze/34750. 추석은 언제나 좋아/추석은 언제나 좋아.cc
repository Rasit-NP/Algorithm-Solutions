# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    int a;
    if (n >= 1'000'000){
        a = n*20/100;
    }
    else if (n >= 500'000){
        a = n*15/100;
    }
    else if (n >= 100'000){
        a = n*10/100;
    }
    else {
        a = n*5/100;
    }

    cout << a << ' ' << n-a;
}