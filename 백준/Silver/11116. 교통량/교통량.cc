# include <iostream>
# include <vector>
# include <set>
using namespace std;

void solve(){
    int m;  cin >> m;
    int res = 0;

    set<int> leftInput, rightInput;
    set<int> leftLine, rightLine;

    for (int i=0; i<m; i++){
        int x;  cin >> x;
        leftInput.insert(x);
    }
    for (int i=0; i<m; i++){
        int x;  cin >> x;
        rightInput.insert(x);
    }

    while (leftInput.size()){
        int x = *leftInput.begin();
        if (leftInput.find(x+500) != leftInput.end()){
            leftInput.erase(x);
            leftInput.erase(x+500);
            leftLine.insert(x);
        }
    }
    while (rightInput.size()){
        int x = *rightInput.begin();
        if (rightInput.find(x+500) != rightInput.end()){
            rightInput.erase(x);
            rightInput.erase(x+500);
            rightLine.insert(x);
        }
    }

    while (leftLine.size() && rightLine.size()){
        int x = *leftLine.begin(), y = *rightLine.begin();
        if (x<=y && rightLine.find(x+1000) != rightLine.end()){
            ++res;
            leftLine.erase(x);
            rightLine.erase(x+1000);
        }
        else if (x>y && leftLine.find(y+1000) != leftLine.end()){
            rightLine.erase(y);
            leftLine.erase(y+1000);
        }
    }

    cout << res << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    while (n--){
        solve();
    }
}