# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    int len[3] = {0, 0, 0};
    int x[3], y[3];
    for (int i=0; i<3; i++){
        cin >> x[i] >> y[i];
    }

    if ((x[0]-x[1])*(y[1]-y[2]) == (x[1]-x[2])*(y[0]-y[1])){
        cout << "X";
        return 0;
    }
    for (int i=0; i<3; i++){
        len[i] += (x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3]) + (y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3]);
    }

    sort(len, len+3);
    if (len[0] == len[1] && len[1] == len[2]){
        cout << "JungTriangle";
        return 0;
    }
    if (len[0] + len[1] == len[2]){
        cout << "Jikkak";
    }
    else if (len[0] + len[1] < len[2]){
        cout << "Dunkak";
    }
    else {
        cout << "Yeahkak";
    }
    if (len[0] == len[1] || len[1] == len[2]){
        cout << 2;
    }
    cout << "Triangle";
}