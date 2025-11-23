# include <iostream>
# include <queue>
# include <vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> ans;
	for (int i=1; i<=n; i++){
		q.push(i);
	}
	while (q.size()){
		for (int i=0; i<k-1; i++){
			int x = q.front();
			q.pop();
			q.push(x);
		}
		ans.push_back(q.front());
		q.pop();
	}
	cout << '<';
	for (int i=0; i<n; i++){
		if (i)
			cout << ", ";
		cout << ans[i];
	}
	cout << '>';
}