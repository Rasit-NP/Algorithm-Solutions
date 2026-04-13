# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct Order{
    int a, b;

    Order(int& a, int& b){
        this->a = a;
        this->b = b;
    }

    bool operator<(Order order){
        if (b < order.b){
            return true;
        }
        else if (b == order.b && a > order.a){
            return true;
        }
        return false;
    }
};

void solve(){
    int n, m;   cin >> n >> m;
    vector<Order> orders;

    for (int i=0; i<m; i++){
        int a, b;   cin >> a >> b;
        orders.emplace_back(a, b);
    }

    sort(orders.begin(), orders.end());
    vector<bool> states(n+1, false);

    int ans = 0;

    for (const Order& order : orders){
        for (int i=order.a; i<=order.b; i++){
            if (!states[i]){
                states[i] = true;
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        solve();
    }
}