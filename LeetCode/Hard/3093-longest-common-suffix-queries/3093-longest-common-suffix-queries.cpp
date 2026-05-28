# include <string>
# include <vector>
# include <map>
using namespace std;

struct Node{
public:
    int bestIdx;
    map<char, Node*> childs;

    Node() {
        this->bestIdx = -1;
    }
};

class Solution {
private:
    Node* nodePool[500001];
    int nodeIdx = 0;

    Node* root;

    void push(int idx, string& word, vector<string>& container){
        int len = word.size();
        Node* now = this->root;

        if (now->bestIdx == -1){
            now->bestIdx = idx;
        }
        else if (container[now->bestIdx].size() > word.size()){
            now->bestIdx = idx;
        }

        for (int i=len-1; i>=0; i--){
            char letter = word[i];
            map<char, Node*>& childs = now->childs;

            if (childs.find(letter) == childs.end()){
                nodePool[nodeIdx] = new Node();
                childs[letter] = nodePool[nodeIdx++];
            }

            now = now->childs[letter];

            if (now->bestIdx == -1){
                now->bestIdx = idx;
            }
            else if (container[now->bestIdx].size() > word.size()){
                now->bestIdx = idx;
            }
        }
    }

    int query(string& word){
        Node* now = this->root;
        int len = word.size();

        for (int i=len-1; i>=0; i--){
            char letter = word[i];
            map<char, Node*>& childs = now->childs;
            
            if (childs.find(letter) != childs.end()){
                now = childs[letter];
            }
            else {
                break;
            }
        }

        return now->bestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        vector<int> res(m, -1);

        this->root = new Node();

        for (int i=0; i<n; i++){
            push(i, wordsContainer[i], wordsContainer);
        }

        for (int i=0; i<m; i++){
            res[i] = query(wordsQuery[i]);
        }

        return res;
    }
};