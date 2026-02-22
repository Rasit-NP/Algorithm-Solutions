# include <iostream>
# include <vector>
using namespace std;

void run(void){
    int c;  cin >> c;

    cout << c / 25 << ' ';
    c %= 25;
    cout << c / 10 << ' ';
    c %= 10;
    cout << c / 5 << ' ';
    c %= 5;
    cout << c << endl;
}

int main(void){
    int t;  cin >> t;
    while (t--){
        run();
    }
}