# include <iostream>
# include <vector>
# include <string>
# define MAX 10000
using namespace std;

int main(void){
    vector<int> res(10001, 0);
    for (int i=1; i<=MAX; i++){
        for (int j=i+1; j<=2*i; j++){
            if ((i*j)%(j-i) == 0){
                res[i]++;
            }
        }
    }
    string n;
    while (cin >> n){
        int x = stoi(n.substr(2, n.size()-2));
        cout << res[x] << '\n';
    }
}