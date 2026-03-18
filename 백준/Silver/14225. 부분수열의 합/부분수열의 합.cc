# include <iostream>
# include <vector>
# include <set>
using namespace std;

int main(void){
    int n;  cin >> n;
    vector<int> list(n, 0);
    set<int> sets;
    for (int& num : list){
        cin >> num;
    }
    for (int i=0; i<(1<<n); i++){
        int num = 0;
        for (int j=0; j<n; j++){
            if (i&(1<<j)){
                num += list[j];
            }
        }
        sets.insert(num);
    }
    int res = 1;
    for (int num : sets){
        if (res < num){
            break;
        }
        else if (res == num){
            res++;
        }
    }
    cout << res;
}