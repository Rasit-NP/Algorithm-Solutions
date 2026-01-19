# include <iostream>
using namespace std;

int main(void){
    int l;  cin >> l;
    if (l>=620 && l<=780){
        cout << "Red";
    }
    else if (l>=590 && l<620){
        cout << "Orange";
    }
    else if (l>=570 && l<590){
        cout << "Yellow";
    }
    else if (l>=495 && l<570){
        cout << "Green";
    }
    else if (l>=450 && l<495){
        cout << "Blue";
    }
    else if (l>=425 && l<450){
        cout << "Indigo";
    }
    else {
        cout << "Violet";
    }
}