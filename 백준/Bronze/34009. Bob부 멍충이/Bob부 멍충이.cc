# include <iostream>
using namespace std;

int main(void){
    int n;    cin >> n;
    for (int i=0; i<n; i++){
        int num;    cin >> num;
    }
    if (n&1){
        cout << "Bob";
    }
    else {
        cout << "Alice";
    }
}