# include <iostream>
# include <vector>
using namespace std;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int n, k, t;    cin >> n >> k >> t;
    vector<int> ans(n, 0);
 
    int x = t * n / 100;
    for (int i=0; i<x; i++){
        ans[i] = k;
    }
 
    for(int i=0; i<=k; i++){
        if ((k*x + i)*100 <= t*n*k){
            continue;
        }
        else if ((k*x + i + 1)*100 > t*n*k){
            ans[x] = i-1;
            break;
        }
    }
 
    for (int i=0; i<n; i++){
        cout << ans[i] << " \n"[i==n-1];
    }
}