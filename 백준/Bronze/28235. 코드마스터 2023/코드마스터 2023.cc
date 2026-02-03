# include <iostream>
# include <string>
using namespace std;

int main(void){
    string input;   cin >> input;
    if (input == "SONGDO")      cout << "HIGHSCHOOL";
    else if (input == "CODE")   cout << "MASTER";
    else if (input == "2023")   cout << "0611";
    else                        cout << "CONTEST";
}