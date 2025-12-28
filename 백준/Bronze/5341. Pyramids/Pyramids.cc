# include <iostream>
using namespace std;

int main(void){
    while (true){
        int n;  cin >> n;
        if (!n) break;
        cout << n*(n+1) / 2 << endl;
    }
}
