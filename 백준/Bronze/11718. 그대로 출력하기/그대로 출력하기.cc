# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string lines;
    while(getline(cin, lines)){
        cout << lines << endl;
    }
}