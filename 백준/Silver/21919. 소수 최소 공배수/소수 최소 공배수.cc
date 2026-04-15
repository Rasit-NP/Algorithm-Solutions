# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

vector<bool> nums(1'000'001, true);

void findPrime(void){
    nums[0] = false, nums[1] = false;
    for (int i=2; i<=1'000'000; i++){
        if (nums[i]){
            for (int x=2*i; x<=1'000'000; x += i){
                nums[x] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    findPrime();

    int n;  cin >> n;
    long long ans = -1;
    unordered_set<int> sets;

    for (int i=0; i<n; i++){
        int x;  cin >> x;
        if (nums[x] && sets.find(x) == sets.end()){
            ans *= x;
            sets.insert(x);
        }
    }

    cout << (ans == -1 ? ans : -ans);
}