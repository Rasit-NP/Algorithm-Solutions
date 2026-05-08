# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(void){
	int n;	cin >> n;
    vector<int> res(n, 0);
    for (int i=0; i<n; i++){
    	cin >> res[i];
    }
    
    sort(res.begin(), res.end());
    cout << res[(n-1)/2];
}