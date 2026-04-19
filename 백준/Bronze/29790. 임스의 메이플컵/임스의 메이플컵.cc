# include <iostream>
using namespace std;

int main(void){
    int n, u, l;    cin >> n >> u >> l;
    
    bool a = n >= 1000;
    bool b = (u>=8000 || l >= 260);
    if (a && b){
        cout << "Very Good";
    }
    else if (a){
        cout << "Good";
    }
    else{
        cout << "Bad";
    }
}