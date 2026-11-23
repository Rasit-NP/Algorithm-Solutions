# include <iostream>
# include <vector>
# include <deque>
using namespace std;

int n;
vector<int> nums;

bool checkIsAble(int);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    nums.assign(n, 0);

    for (int i=0; i<n; ++i){
        cin >> nums[i];
    }

    int l = 0, r = n;

    while (r-l > 1){
        int mid = (l+r)/2;

        if (checkIsAble(mid)){
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r << '\n';
}

bool checkIsAble(int k){
    deque<int> maxQ;
    int maxVal;
    for (int i=0; i<k; ++i){
        int val = nums[i];
        if (maxQ.empty() || maxQ.back() <= val){
            maxQ.push_back(val);
        }
    }

    maxVal = maxQ.back();

    for (int i=0; i<n-k; ++i){
        int val = nums[i+k];
        int befVal = nums[i];
        if (maxQ.front() == befVal){
            maxQ.pop_front();
        }

        if (maxQ.empty() || maxQ.back() <= val){
            maxQ.push_back(val);
        }

        if (maxQ.back() < maxVal)
            return false;
        else {
            maxVal = maxQ.back();
        }
    }
    return true;
}