# include <iostream>
# include <vector>
# include <unordered_set>
# include <algorithm>
using namespace std;

int trans(int i, int j, int k, int l){
    return min(1000*i+100*j+10*k+l, min(1000*j+100*k+10*l+i, min(1000*k+100*l+10*i+j, 1000*l+100*i+10*j+k)));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> nums(4, 0);
    unordered_set<int> sets;
    vector<int> data;
    for (int i=1; i<10; i++){
        for (int j=1; j<10; j++){
            for (int k=1; k<10; k++){
                for (int l=1; l<10; l++){
                    sets.insert(trans(i, j, k, l));
                }
            }
        }
    }
    for (int num: sets){
        data.push_back(num);
    }
    sort(data.begin(), data.end());
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    int num = trans(nums[0], nums[1], nums[2], nums[3]);
    int ans = lower_bound(data.begin(), data.end(), num) - data.begin();
    cout << ans + 1 << '\n';
}