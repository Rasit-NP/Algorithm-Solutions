# include <iostream>
# include <vector>
using namespace std;

struct Node {
	int value;
	Node* left = nullptr;
	Node* right = nullptr;
};

void insert(vector<Node*>* tree, int x) {
	Node* now_node = (*tree)[0];
	while (true) {
		int value = now_node->value;
		if (x < value) {
			if (now_node->left != nullptr)
				now_node = now_node->left;
			else {
				Node* node = new Node;
				node->value = x;
				now_node->left = node;
				break;
			}
		}
		else {
			if (now_node->right != nullptr)
				now_node = now_node->right;
			else {
				Node* node = new Node;
				node->value = x;
				now_node->right = node;
				break;
			}
		}
	}
}

void dfs(Node* now_node) {
	if (now_node->left != nullptr) {
		dfs(now_node->left);
	}
	if (now_node->right != nullptr) {
		dfs(now_node->right);
	}
	cout << now_node->value << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<Node*> tree;
	int x;
	cin >> x;
	Node* root = new Node();
	root->value = x;
	tree.push_back(root);

	while (true) {
		int x;
		cin >> x;
		if (cin.eof())	break;
		insert(&tree, x);
	}
	dfs(root);
}