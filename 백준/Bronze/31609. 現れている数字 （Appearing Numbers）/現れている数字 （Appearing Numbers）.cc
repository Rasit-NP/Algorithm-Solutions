# include <iostream>
# include <set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    set<int> nums;
    int n;  cin >> n;
    for (int i=0; i<n; i++){
        int a;  cin >> a;
        nums.insert(a);
    }

    for (int num : nums){
        cout << num << '\n';
    }
}