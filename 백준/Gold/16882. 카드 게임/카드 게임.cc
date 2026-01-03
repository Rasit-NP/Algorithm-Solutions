# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int n;  cin >> n;
    int largest = 0, cnt = 0;
    int num;
    for (int i=0; i<n; i++){
        cin >> num;
        if (num > largest){
            largest = num;
            cnt = 1;
        }
        else if (num == largest){
            cnt++;
        }
    }
    if (cnt&1){
        cout << "koosaga\n";
    }
    else {
        if (cnt == n)
            cout << "cubelover\n";
        else
            cout << "koosaga\n";
    }
}