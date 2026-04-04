# include <iostream>
using namespace std;

int main(void){
    int n;    cin >> n;
    n--;
    
    cout << "WelcomeToSMUPC"[n%14];
}