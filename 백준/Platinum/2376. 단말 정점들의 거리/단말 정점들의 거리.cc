# include <iostream>
# include <vector>
# include <queue>
using namespace std;

struct Edge;

struct Node{
    int level;
    Node* parent = nullptr;
    Node* leftchild = nullptr;
    Node* rightchild = nullptr;
};

int n;
deque<Node*> nodes;
deque<int> dists;
vector<Node*> node_data;

void dfs(Node* node){
    Node* left = node -> leftchild;
    Node* right = node -> rightchild;
    if (left == nullptr){
        return;
    }
    left -> level = node -> level + 1;
    right -> level = node -> level + 1;
    dfs(left);
    dfs(right);
}

int main(void){
    cin >> n;
    for (int i=0; i<n; i++){
        nodes.push_back(new Node());
        node_data.push_back(nodes.back());
    }
    for (int i=0; i<n-1; i++){
        int dist;   cin >> dist;
        dists.push_back(dist);
    }
    while(dists.size()){
        deque<int> sub_dists;
        deque<Node*> sub_nodes;
        while(dists.size()){
            if (dists.front() == 2){
                if (sub_dists.size()){
                    sub_dists.back()--;
                }
                dists.pop_front();
                if (dists.size()){
                    dists.front()--;
                }
                Node* parent = new Node();
                parent->leftchild = nodes.front();  nodes.pop_front();
                parent->rightchild = nodes.front(); nodes.pop_front();
                parent->leftchild->parent = parent;
                parent->rightchild->parent = parent;
                nodes.push_front(parent);
            }
            else {
                sub_dists.push_back(dists.front());     dists.pop_front();
                sub_nodes.push_back(nodes.front());     nodes.pop_front();
            }
        }
        if (nodes.size()){
            sub_nodes.push_back(nodes.front());     nodes.pop_front();
        }
        nodes = sub_nodes;
        dists = sub_dists;
    }
    Node* root = nodes.front();
    root -> level = 0;
    dfs(root);

    int l, r;   cin >> l >> r;
    Node* left = node_data[l-1];
    Node* right = node_data[r-1];

    int cnt = 0;
    while (left->level > right->level){
        left = left->parent;
        cnt++;
    }
    while (right->level > left->level){
        right = right->parent;
        cnt++;
    }
    while (left != right){
        left = left -> parent;
        right = right -> parent;
        cnt += 2;
    }
    cout << cnt << '\n';
}