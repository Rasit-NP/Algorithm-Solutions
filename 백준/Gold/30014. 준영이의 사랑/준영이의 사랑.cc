# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    deque<int> dq;
    deque<int> ans;
    for (int i=0; i<n; i++){
        int num;    cin >> num;
        dq.push_back(num);
    }
    sort(dq.begin(), dq.end());

    for (int i=0; i<n; i++){
        int num = dq.back(); dq.pop_back();
        if (i & 1){
            ans.push_back(num);
        }
        else {
            ans.push_front(num);
        }
    }
    int res = ans.front() * ans.back();
    vector<int> resVec;
    while (ans.size() > 1){
        int num = ans.front();   ans.pop_front();
        res += num * ans.front();
        resVec.push_back(num);
    }
    resVec.push_back(ans.front());  ans.pop_front();

    cout << res << '\n';
    for (int i=0; i<n; i++){
        cout << resVec[i] << " \n"[i == n-1];
    }
}