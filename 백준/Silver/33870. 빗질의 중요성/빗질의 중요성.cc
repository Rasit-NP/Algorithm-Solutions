# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<int> tempo(n, 0);
    vector<int> orders(m, 0);
    vector<int> latest(n, -1);
    vector<int> states(n, 0);
    int ans=0;
    for (int& num : tempo){
        cin >> num;
    }
    for (int& order : orders){
        cin >> order;
        order--;
    }
    for (int i=0; i<m; i++){
        int pet = orders[i];
        if (states[pet] == 1 && latest[pet] == i-1){
            states[pet] = 0;
        }
        else if (states[pet] == 0){
            if (i - latest[pet] > tempo[pet]){
                states[pet] = 1;
            }
        }
        latest[pet] = i;
    }
    for (int pet=0; pet<n; pet++){
        if (m - latest[pet] > tempo[pet]){
            states[pet] = 1;
        }
        if (states[pet]){
            ans++;
        }
    }
    cout << ans;
}