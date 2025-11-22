# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

vector<vector<long long>> product(int size, vector<vector<long long>>& matA, vector<vector<long long>>& matB) {
	int i, j, k;
	vector<vector<long long>> res(size, vector<long long>(size, 0));
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			long long total = 0;
			for (k = 0; k < size; k++) {
				total += (matA[i][k] * matB[k][j])%1000000007;
			}
			res[i][j] = total % 1000000007;
		}
	}
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n, d;
	cin >> t >> n >> d;
	vector<vector<vector<long long>>> matrixes;
	vector<vector<long long>> cycle_matrix(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		cycle_matrix[i][i] = 1;
	}
	for (int term = 0; term < t; term++) {
		int m;
		cin >> m;
		vector<vector<long long>> matrix(n, vector<long long>(n, 0));
		for (int i = 0; i < m; i++) {
			int a, b;
			long long c;
			cin >> a >> b >> c;
			matrix[a-1][b-1] = c;
		}
		matrixes.push_back(matrix);
		cycle_matrix = product(n, cycle_matrix, matrix);
	}

	int times = d / t;
	int loss = d % t;

	vector<vector<long long>> ans(n, vector<long long>(n, 0));
	vector<vector<long long>> bias(n, vector<long long>(n, 0));
	for (int i = 0; i < n; i++) {
		ans[i][i] = 1;
		for (int j = 0; j < n; j++) {
			bias[i][j] = cycle_matrix[i][j];
		}
	}

	for (; times>0; times = times >> 1, bias = product(n, bias, bias)){
		if (times&1){
			ans = product(n, ans, bias);
		}
	}

	for (int i=0; i<loss; i++){
		ans = product(n, ans, matrixes[i]);
	}
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < n-1; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << ans[i][j] << '\n';
	}
}