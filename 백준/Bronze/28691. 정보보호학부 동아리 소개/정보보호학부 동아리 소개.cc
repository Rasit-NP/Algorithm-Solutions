# include <iostream>
using namespace std;

int main(void){
    char let;   cin >> let;
    if (let == 'M')
        cout << "MatKor";
    if (let == 'W')
        cout << "WiCys";
    if (let == 'C')
        cout << "CyKor";
    if (let == 'A')
        cout << "AlKor";
    if (let == '$')
        cout << "$clear";
}