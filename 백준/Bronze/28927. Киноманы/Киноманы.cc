# include <iostream>
using namespace std;

int cal(int& t, int& e, int& f){
    return 3*t + 20*e + 120*f;
}

int main(void){
    int t1, e1, f1, t2, e2, f2;
    cin >> t1 >> e1 >> f1;
    cin >> t2 >> e2 >> f2;
    
    int res1 = cal(t1, e1, f1), res2 = cal(t2, e2, f2);
    
    cout << (res1 > res2 ? "Max" : (res1 < res2 ? "Mel" : "Draw"));
}