# include <iostream>
# include <vector>
using namespace std;

int main(void){
    int n;  cin >> n;
    vector<int> count(21, 0);
    for (int i=0; i<n; i++){
        int x;  cin >> x;
        count[x]++;
    }

    for (int i=20; i>1; i--){
        if (count[i]){
            count[i-1] += count[i]/2;
        }
    }

    cout << (count[1] >= 2 ? "A" : "B");
}