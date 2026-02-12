# include <iostream>
# include <queue>
using namespace std;

int main(void){
    int n;  cin >> n;

    queue<int> q;
    while (true){
        int order;  cin >> order;
        if (order == -1)
            break;
        else if (order == 0){
            q.pop();
        }
        else if (q.size() < n){
            q.push(order);
        }
    }
    if (!q.size()){
        cout << "empty";
    }
    for (int i=0, size = q.size(); i < size; i++){
        if (i)
            cout << ' ';
        cout << q.front();  q.pop();
    }
}