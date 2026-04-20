# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    long long n;  cin >> n;
    long long one = 1;
    if (n>=-(1<<15) && (n<=(1<<15)-1)){
        cout << "short";
    }
    else if (n>=-(one<<31) && (n<=(one<<31)-1)){
        cout << "int";
    }
    else {
        cout << "long long";
    }
}