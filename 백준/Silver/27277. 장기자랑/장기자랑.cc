# include <iostream>
# include <deque>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;              cin >> n;
    deque<int> data;
    deque<int> ans;

    for (int i=0; i<n; i++){
        int num;    cin >> num;
        data.push_back(num);
    }
    sort(data.begin(), data.end());

    ans.push_front(data.back()); data.pop_back();

    while(data.size()){
        if (ans.front() >= data.back()){
            ans.push_front(data.front());   data.pop_front();
        }
        else {
            ans.push_front(data.back());    data.pop_back();
        }
    }

    int res = 0, now = 0;

    while (ans.size()){
        res += max(0, ans.front() - now);
        now = ans.front();  ans.pop_front();
    }

    cout << res;
}