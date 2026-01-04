# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int x;  cin >> x;
    if (x<13)   cout << x;
    else        cout << x+1;
}