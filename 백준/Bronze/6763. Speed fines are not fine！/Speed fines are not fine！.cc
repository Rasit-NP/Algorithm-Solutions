# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int a, b;   cin >> a >> b;
    int over = b-a;

    if (over <= 0){
        cout << "Congratulations, you are within the speed limit!\n";
    }
    else if (over <= 20){
        cout << "You are speeding and your fine is $100.\n";
    }
    else if (over <= 30){
        cout << "You are speeding and your fine is $270.\n";
    }
    else {
        cout << "You are speeding and your fine is $500.\n";
    }
}