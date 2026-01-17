# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    string input;   cin >> input;
    if (input == "NLCS"){
        cout << "North London Collegiate School\n";
    }
    else if (input == "BHA"){
        cout << "Branksome Hall Asia\n";
    }
    else if (input == "KIS"){
        cout << "Korea International School\n";
    }
    else {
        cout << "St. Johnsbury Academy\n";
    }
}