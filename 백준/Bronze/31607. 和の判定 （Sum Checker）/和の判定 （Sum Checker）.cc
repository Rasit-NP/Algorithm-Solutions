# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int nums[3];
    for (int i=0; i<3; i++){
        cin >> nums[i];
    }
    sort(nums, nums+3);
    cout << (nums[0] + nums[1] == nums[2]);
}