# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int trans(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h*60 + m;
}

int main(void){
    string time1, time2;    cin >> time1 >> time2;
    int trans1 = trans(time1), trans2 = trans(time2);

    int diff = max(trans1, trans2) - min(trans1, trans2);
    if (diff >= 360){
        diff = 720 - diff;
    }
    cout << diff*6 << endl;
}