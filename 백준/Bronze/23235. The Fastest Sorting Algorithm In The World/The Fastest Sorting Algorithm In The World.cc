# include <iostream>
# include <string>
using namespace std;

int main(void){
    string s;
    while(true){
        getline(cin, s);
        if (s == "0")    break;
        static int tc = 1;
        cout << "Case " << tc++ << ": Sorting... done!\n";
    }
}