# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<int> position(8, 0);
    for (int i=0; i<=7; i++){
        position[i] = i;
    }
    for (int i=0; i<n; i++){
        int order;  cin >> order;
        int cnt = 0, idx1, idx2;
        for (int bit=0; bit<8; bit++){
            if (order & (1<<bit)){
                if (cnt == 0){
                    idx1 = bit;
                }
                else if (cnt == 1){
                    idx2 = bit;
                }
                else if (cnt++ == 2)
                    break;
                cnt++;
            }
        }
        if (cnt == 2){
            swap(position[idx1], position[idx2]);
        }
    }
    int k;  cin >> k;
    cout << position[k] << '\n';
}