# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <string>
# include <cmath>
#include <iomanip>
using namespace std;

struct Node {
	char letter;
	bool end = false;
	int idx[26] = {0};
	int length = 0;
	vector<Node*> childs;
};

vector<int> ans;

int push(Node* node, string word){
	for (int i=0; i<word.length(); i++){
		char letter = word[i];
		int idx = node->idx[letter-'a'];
		if (idx){
			node = node->childs[idx-1];
		}
		else{
			Node* new_node = new Node;
			new_node->letter = letter;
			node->childs.push_back(new_node);
			node->length += 1;
			node->idx[letter-'a'] = node->length;
			node = node->childs[node->length-1];
		}
	}
	node->end = true;
	return 0;
}

int run(Node* node, int cnt){
	if (node->end){
		ans.push_back(cnt);
	}
	int now_cnt = cnt;
	if (node->length > 1 || (node->length == 1 && node->end) || cnt == 0){
		now_cnt += 1;
	}
	for (Node* child: node->childs){
		run(child, now_cnt);
	}
	for (Node* child : node->childs)
		delete(child);
	return 0;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	while (cin >> n){
		Node root;
		ans.clear();
		for (int i=0; i<n; i++){
			string word;
			cin >> word;
			push(&root, word);
		}
		run(&root, 0);
		double sum = 0;
		for (int num: ans){
			sum += num;
		}
		double fin = (sum*100)/n;
		cout << fixed << setprecision(2) << round(fin)/100 << '\n';
		ans.clear();
	}
}