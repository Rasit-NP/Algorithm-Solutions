# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    int lens[3];
    for (int i=0; i<3; i++){
        cin >> lens[i];
    }
    
    sort(lens, lens+3);
    cout << lens[0] + lens[1] + min(lens[0] + lens[1] - 1, lens[2]);
}