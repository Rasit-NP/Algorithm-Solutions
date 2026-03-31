# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, k;   cin >> n >> k;
    vector<int> diff(1'000'002, 0);
    vector<long long> sums(1'000'002, 0);

    for (int i=0; i<n; i++){
        int a, b;   cin >> a >> b;
        diff[a] += 1;
        diff[b] -= 1;
    }
    sums[0] = diff[0];
    for (int i=1; i<1'000'002; i++){
        sums[i] = sums[i-1] + diff[i];
    }

    int a = 0, b = 1;
    long long val = sums[a];
    while (b < 1'000'002){
        if (val == k){
            break;
        }
        else if (val < k){
            val += sums[b++];
        }
        else {
            val -= sums[a++];
        }
    }

    if (b == 1'000'002){
        cout << "0 0";
    }
    else {
        cout << a << ' ' << b;
    }
}