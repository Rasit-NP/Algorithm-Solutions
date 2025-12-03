# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, cnt=0;
    cin >> n >> k;
    for (int i=0; i<k; i++){
        int a;
        cin >> a;
        cnt += (a+1)/2;
    }
    if (cnt>=n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}