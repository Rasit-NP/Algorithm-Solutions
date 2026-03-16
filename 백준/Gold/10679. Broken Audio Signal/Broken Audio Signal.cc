# include <iostream>
# include <vector>
# include <string>
# define INT_MIN -1000000005
# define INT_MAX 1000000005
using namespace std;

void run(int n){
    vector<int> disk(n+2);
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int cnt=0;
    bool able = true;
    disk[0] = INT_MIN;
    for (int i=1; i<=n; i++){
        string val; cin >> val;
        if (val != "x"){
            disk[i] = stoi(val);
            cnt++;
            if (disk[i-1] != INT_MIN){
                if ((i&1) && disk[i] >= disk[i-1]){
                    able = false;
                }
                else if (!(i&1) && disk[i] <= disk[i-1]){
                    able = false;
                }
            }
        }
        else{
            disk[i] = INT_MIN;
            if (disk[i-1] == INT_MIN){
                if (i == 1){
                    continue;
                }
                able = false;
            }
        }
    }
    disk[n+1] = INT_MIN;

    for (int i=1; i<=n; i++){
        if (disk[i] == INT_MIN){
            if (i&1){
                if (disk[i-1] != INT_MIN){
                    maxi = min(maxi, disk[i-1]);
                }
                if (disk[i+1] != INT_MIN){
                    maxi = min(maxi, disk[i+1]);
                }
            }
            else {
                if (disk[i-1] != INT_MIN){
                    mini = max(mini, disk[i-1]);
                }
                if (disk[i+1] != INT_MIN){
                    mini = max(mini, disk[i+1]);
                }
            }
        }
    }

    if (!able){
        cout << "none\n";
        return;
    }
    else if (maxi-mini == 2){
        cout << mini + 1 << '\n';
        return;
    }
    else if (maxi-mini > 2){
        cout << "ambiguous\n";
        return;
    }
    else {
        cout << "none\n";
        return;
    }
}

int main(void){
    while (true){
        int n;  cin >> n;
        if (!n){
            break;
        }
        run(n);
    }
}