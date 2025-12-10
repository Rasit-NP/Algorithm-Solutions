# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum;
    vector<int> lst;
    while(true){
        cin >> n;
        sum = 0;
        if (n==-1)  break;
        lst.clear();
        for (int i=1; i<n; i++){
            if (!(n%i)){
                sum += i;
                lst.push_back(i);
            }
        }
        if (sum != n){
            cout << n << " is NOT perfect.\n";
            continue;
        } else {
            cout << n << " =";
            for (int i=0; i<lst.size(); i++){
                if (i)  cout << " +";
                cout << ' ' << lst[i];
            }
            cout << '\n';
        }
    }
}