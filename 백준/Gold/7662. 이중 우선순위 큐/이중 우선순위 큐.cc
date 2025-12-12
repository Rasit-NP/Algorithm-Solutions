# include <iostream>
# include <queue>
# include <unordered_map>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int tc=1; tc<=t; tc++){
		int k;
		priority_queue<long long> max_heap;
		priority_queue<long long> min_heap;
		unordered_map<int, int> cnt;
		char order;
		long long n;
		cin >> k;
		for (int query=0; query<k; query++){
			cin >> order >> n;
			if (order == 'I'){
				max_heap.push(n);
				min_heap.push(-n);
				if (cnt.find(n) != cnt.end()){
					cnt[n]++;
				} else {
					cnt[n] = 1;
				}
			} else if (order == 'D' && n == -1){
				while (true){
					if (min_heap.size() == 0)	break;
					int x = -min_heap.top();
					min_heap.pop();
					if (cnt[x] > 0){
						cnt[x]--;
						break;
					} else {
						continue;
					}
				}
			} else if (order == 'D' && n == 1){
				while (true){
					if (max_heap.size() == 0)	break;
					int x = max_heap.top();
					max_heap.pop();
					if (cnt[x] > 0){
						cnt[x]--;
						break;
					} else {
						continue;
					}
				}

			}
		}
		while (true){
			if (max_heap.size() == 0){
				cout << "EMPTY";
				break;
			}
			int x = max_heap.top();
			max_heap.pop();
			if (cnt[x] == 0){
				continue;
			} else {
				cout << x << ' ';
				break;
			}
		}
		while (true){
			if (min_heap.size() == 0){
				break;
			}
			int x = -min_heap.top();
			min_heap.pop();
			if (cnt[x] == 0){
				continue;
			} else {
				cout << x;
				break;
			}
		}
		cout << '\n';
	}
}