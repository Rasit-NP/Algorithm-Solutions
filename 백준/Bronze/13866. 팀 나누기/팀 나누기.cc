# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    vector<int> nums(4, 0);

    for (int i=0; i<4; ++i){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    cout << abs(nums[3] + nums[0] - nums[1] - nums[2]);
}