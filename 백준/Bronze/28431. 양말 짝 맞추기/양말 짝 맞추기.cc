# include <iostream>
# include <set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    set<int> sets;    
    for (int i=0; i<5; i++){
        int x;  cin >> x;
        if (sets.find(x) == sets.end()){
            sets.insert(x);
        }
        else {
            sets.erase(x);
        }
    }
    cout << *sets.begin();
}