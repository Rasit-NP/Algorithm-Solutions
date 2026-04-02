# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
# include <unordered_set>
using namespace std;

struct Node{
    char letter;
    unordered_map<char, Node*> childs;
    bool isEnd;
    bool isColor;

    Node(char let, bool isColor){
        this->letter = let;
        this->isColor = isColor;
        this->isEnd = false;
    }
    Node():Node('.', false){}
};

Node colorInit;
int nodeCount = 0;
vector<Node> pool;
unordered_set<string> sets;

void insert(Node* node, string& word, int idx, int isColor){
    if (idx == word.size()){
        node->isEnd = true;
        return;
    }
    char letter = word[idx];
    unordered_map<char, Node*>& childs = node->childs;

    if (childs.find(letter) == childs.end()) {
        Node newNode = Node(letter, isColor);
        pool.push_back(newNode);
        childs[letter] = &pool[nodeCount++];
    }
    insert(childs[letter], word, ++idx, isColor);
}

bool check(Node* node, string& word, int idx){
    if (idx == word.size()){
        if (!(node->isColor)){
            return true;
        }
        else {
            return false;
        }
    }
    char letter = word[idx];
    unordered_map<char, Node*>& childs = node->childs;
    if (node->isColor && node->isEnd && sets.find(word.substr(idx, word.size()-idx)) != sets.end()){
        return true;
    }
    if (childs.find(letter) == childs.end()){
        return false;
    }
    return check(childs[letter], word, idx+1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int c, n;   cin >> c >> n;

    pool.reserve(1001*c);
    
    
    for (int i=0; i<c; i++){
        string color;    cin >> color;
        insert(&colorInit, color, 0, true);
    }
    for (int i=0; i<n; i++){
        string name;    cin >> name;
        sets.insert(name);
    }

    int q;  cin >> q;
    for (int i=0; i<q; i++){
        string team;    cin >> team;
        if (check(&colorInit, team, 0)){
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}