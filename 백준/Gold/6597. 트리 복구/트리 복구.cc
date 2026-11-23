# include <iostream>
# include <vector>
# include <string>
using namespace std;

void solve(string&, string&);
string getPostOrder(char, vector<int>&, vector<int>&);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string line;

    while (getline(cin, line)){
        int sp = line.find(' ');
        string preOrder = line.substr(0, sp);
        string inOrder = line.substr(sp+1, line.size()-sp);

        solve(preOrder, inOrder);
    }
}

void solve(string& preOrder, string& inOrder){
    int n = preOrder.size();
    int preOrderIdx = 0;
    int inOrderIdx = 0;

    vector<int> leftChild(26, -1), rightChild(26, -1), visited(26, 0);

    char node = preOrder[0];
    visited[node-'A'] = 1;
    for (; preOrderIdx < n; ++preOrderIdx){
        char now = preOrder[preOrderIdx];

        while (visited[inOrder[inOrderIdx] - 'A']){
            node = inOrder[inOrderIdx++];
            visited[node-'A'] = 2;
        }

        if (node == now)
            continue;
        else if (visited[node-'A'] == 1){
            leftChild[node-'A'] = now;
            node = now;
            visited[node-'A'] = 1;
        }
        else if (visited[node-'A'] == 2){
            rightChild[node-'A'] = now;
            node = now;
            visited[node-'A'] = 1;
        }
    }

    cout << getPostOrder(preOrder[0], leftChild, rightChild) << '\n';
}

string getPostOrder(char root, vector<int>& leftChilds, vector<int>& rightChilds){

    string res = "";

    char leftChild = leftChilds[root-'A'];
    char rightChild = rightChilds[root-'A'];

    if (leftChild != -1){
        res += getPostOrder(leftChild, leftChilds, rightChilds);
    }
    if (rightChild != -1){
        res += getPostOrder(rightChild, leftChilds, rightChilds);
    }

    res.push_back(root);

    return res;
}