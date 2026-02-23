# include <iostream>
using namespace std;

int main(void){
    int n;    cin >> n;
    
    int two, five;
    
    five = n/5;
    n %= 5;
    
    if ((n&1) && five > 0){
        five -= 1;
        n += 5;
        two = n/2;
    }
    else if (!(n&1)){
        two = n/2;
    }
    else{
        cout << -1;
        return 0;
    }
    cout << five + two;
}