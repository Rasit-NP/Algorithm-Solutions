# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string name;    cin >> name;
    if (name[0] == 'F'){
        cout << "Foundation";
    }
    else if (name[0] == 'C'){
        cout << "Claves";
    }
    else if (name[0] == 'V'){
        cout << "Veritas";
    }
    else{
        cout << "Exploration";
    }
}