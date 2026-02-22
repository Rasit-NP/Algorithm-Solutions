# include <iostream>
# include <string>
# include <unordered_set>
using namespace std;

int main(void){
    int n;  cin >> n;
    unordered_set<string> sets;
    for (int i=0; i<n; i++){
        string mat; cin >> mat;
        sets.insert(mat);
    }
    for (int i=0; i<n-1; i++){
        string mat; cin >> mat;
        sets.extract(mat);
    }
    cout << *sets.begin() << endl;
}