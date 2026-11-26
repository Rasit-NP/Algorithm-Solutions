# include <iostream>
# include <queue>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n, k;   cin >> n >> k;
    int res = 1 << 30;
    queue<int> q;

    for (int i=0; i<n; ++i){
        int num;    cin >> num;

        if (num == 1)
            q.push(i);
        else 
            continue;

        while (q.size() > k){
            q.pop();
        }

        if (q.size() == k){
            res = min(res, i-q.front()+1);
        }
    }

    cout << (res != (1 << 30) ? res : -1) << '\n';
}