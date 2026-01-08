# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<int> person(n, 0);
    vector<int> range(n-1, 0);
    for (int i=0; i<n; i++){
        cin >> person[i];
    }
    for (int i=0; i<n-1; i++){
        cin >> range[i];
    }
    int position = 0;
    int left = 0;
    int idx = 0;
    bool res = false;
    while (true){
        if (person[idx] <= position){
            if (idx<n-1){
                left = max(left, range[idx]+person[idx]-position);
            }
            else{
                res = true;
                break;
            }
            idx++;
        }
        else {
            if (left--){
                position++;
            }
            else {
                break;
            }
        }
    }
    if (res){
        cout << "권병장님, 중대장님이 찾으십니다\n";
    }
    else {
        cout << "엄마 나 전역 늦어질 것 같아\n";
    }
}