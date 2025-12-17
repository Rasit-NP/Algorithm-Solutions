# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<char> eggplants;
    for (int i=0; i<n; i++){
        char eggplant; cin >> eggplant;
        eggplants.push_back(eggplant);
    }
    int m, k; cin >> m >> k;
    bool check1 = false;
    for (int i=0; i<m; i++){
        bool check = true;
        for (int j=0; j<k; j++){
            int idx; cin >> idx;
            if (eggplants[idx-1] == 'P'){
                check = false;
            }
        }
        if (check){
            check1 = true;
        }
    }
    if (check1){
        cout << "W\n";
    }
    else {
        cout << "P\n";
    }
}