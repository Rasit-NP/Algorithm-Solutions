# include <iostream>
# include <vector>
# include <tuple>
# include <unordered_map>
# include <climits>
# include <algorithm>
# define llong long long
using namespace std;

struct Node{
    llong score;
    unordered_map<char, tuple<Node*, llong, llong>> childs;

    Node(){
        this->score = 0;
    }
};

Node* prefixInit;
Node* suffixInit;
vector<Node> pool;

pair<llong, llong> insert(Node* node, string& word, int idx, const int& score){
    if (idx == word.size()){
        node->score = score;

        llong mini = 0, maxi = 0;
        unordered_map<char, tuple<Node*, llong, llong>>& childs = node->childs;
        for (const auto& [key, t] : childs){
            mini = min(mini, get<1>(t));
            maxi = max(maxi, get<2>(t));
        }
        return {score + mini, score + maxi};
    }

    char let = word[idx];
    unordered_map<char, tuple<Node*, llong, llong>>& childs = node->childs;
    if (childs.find(let) == childs.end()){
        Node newNode;
        pool.push_back(newNode);
        childs[let] = {&(pool[pool.size()-1]), 0, 0};
    }
    
    pair<llong, llong> p = insert(get<0>(childs[let]), word, idx+1, score);
    childs[let] = {get<0>(childs[let]), p.first, p.second};
    
    llong mini = 0, maxi = 0;
    for (const auto& [key, t] : childs){
        mini = min(mini, get<1>(t));
        maxi = max(maxi, get<2>(t));
    }
    return {node->score + mini, node->score + maxi};
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int q;  cin >> q;
    pool.reserve(1'000'010);
    prefixInit = new Node();
    suffixInit = new Node();

    while (q--){
        string word;
        int score;
        char order; cin >> order;
        if (order == '<'){
            cin >> word >> score;
            insert(prefixInit, word, 0, score);
        }
        else if (order == '>'){
            cin >> word >> score;
            reverse(word.begin(), word.end());
            insert(suffixInit, word, 0, score);
        }
        else if (order == '+'){
            llong premaxi = 0;
            llong sufmaxi = 0;
            for (const auto& [key, tup] : prefixInit->childs){
                premaxi = max(premaxi, get<2>(tup));
            }
            for (const auto& [key, tup] : suffixInit->childs){
                sufmaxi = max(sufmaxi, get<2>(tup));
            }
            cout << premaxi + sufmaxi << '\n';
        }
        else {
            llong premini = 0;
            llong sufmini = 0;
            for (const auto& [key, tup] : prefixInit->childs){
                premini = min(premini, get<1>(tup));
            }
            for (const auto& [key, tup] : suffixInit->childs){
                sufmini = min(sufmini, get<1>(tup));
            }
            cout << premini + sufmini << '\n';
        }
    }
}