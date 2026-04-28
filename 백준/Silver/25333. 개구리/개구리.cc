# include <iostream>
# include <algorithm>
using namespace std;

int getGcd(int a, int b){
    if (b > a){
        swap(a, b);
    }

    while (a % b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }

    return b;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        int a, b;   cin >> a >> b;
        int x;      cin >> x;

        int g = getGcd(a, b);

        cout << x / g << '\n';
    }
}