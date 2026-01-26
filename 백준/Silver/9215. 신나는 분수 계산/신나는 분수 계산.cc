# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> pharse(string num){
    vector<int> res(3, 0);
    int com_idx, slsh_idx;
    int a, b, c;
    if (num.find(',') == string::npos){
        com_idx = -1;
        a = 0;
    }
    else {
        com_idx = num.find(',');
        a = stoi(num.substr(0, com_idx));
    }
    if (num.find('/') == string::npos){
        a = stoi(num);
        b = 0;
        c = 1;
    }
    else {
        slsh_idx = num.find('/');
        b = stoi(num.substr(com_idx+1, slsh_idx-com_idx-1));
        c = stoi(num.substr(slsh_idx+1, num.length()-slsh_idx-1));
    }
    res = {a, b, c};
    return res;
}

int getGcd(int a, int b){
    int x = max(a, b); int y = min(a, b);
    int temp;
    while (x%y){
        temp = x%y;
        x = y; y = temp;
    }

    return y;
}

vector<int> add(vector<int> a, vector<int> b){
    vector<int> res = {a[0]+b[0], a[1]*b[2]+a[2]*b[1], a[2]*b[2]};
    if (res[1] >= res[2]){
        res[0] += res[1] / res[2];
        res[1] %= res[2];
    }
    if (res[1] != 0){
        int gcd = getGcd(res[1], res[2]);
        res[1] /= gcd; res[2]/= gcd;
    }

    return res;
}

void print(vector<int> num){
    if (num[1] == 0){
        cout << num[0];
        return;
    }
    else if (num[0] != 0){
        cout << num[0] << ',';
    }
    cout << num[1] << '/' << num[2];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;
    int tc = 1;
    while(cin >> n){
        if (n == 0)
            break;
        vector<vector<int>> nums;
        for (int i=0; i<n; i++){
            string num; cin >> num;
            nums.push_back(pharse(num));
        }
        vector<int> ans = {0, 0, 1};
        for (vector<int> num : nums){
            ans = add(ans, num);
        }
        cout << "Test " << tc++ << ": ";
        print(ans);
        cout << '\n';
    }
}