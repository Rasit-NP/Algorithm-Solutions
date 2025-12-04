# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    int q, order;
    cin >> q;
    vector<int> arr(q+1, 0);
    vector<int> sums(q+1, 0);
    int head=1, size=0;
    for (int query=0; query<q; query++){
        cin >> order;
        if (order == 1){
            int x;
            cin >> x;
            arr[head+size] = x;
            sums[head+size] = sums[head+size-1] + x;
            size++;
        }
        else if (order == 2){
            int mid = size/2;
            int sum_front = sums[head+mid-1] - sums[head-1];
            int sum_back = sums[head+size-1] - sums[head+mid-1];
            if (sum_front > sum_back){
                cout << sum_back << '\n';
                size /= 2;
            }
            else {
                cout << sum_front << '\n';
                head = head + mid;
                size = (size+1)/2;
            }
        }
    }
    for (int i=0; i<size; i++){
        if (i)  cout << ' ';
        cout << arr[head+i];
    }
}