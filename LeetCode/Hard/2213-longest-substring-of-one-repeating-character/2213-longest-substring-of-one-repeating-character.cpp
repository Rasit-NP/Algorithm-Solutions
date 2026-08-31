# include <string>
# include <vector>
# include <algorithm>
using namespace std;

struct Node{
    int prefLen = 1;
    int sufLen = 1;
    int maxLen = 1;
    int len = 1;
    char leftChar, rightChar;

    bool check(){
        return prefLen == sufLen && sufLen == len;
    }

    void init(char c){
        prefLen = sufLen = maxLen = len = 1;
        leftChar = rightChar = c;
    }

    void merge(Node& left, Node& right){
        if (left.len == 0){
            return;
        }
        else if (right.len == 0){
            prefLen = left.prefLen;
            sufLen = left.sufLen;
            maxLen = left.maxLen;
            len = left.len;
            leftChar = left.leftChar;
            rightChar = left.rightChar;
            return;
        }
        else {
            bool leftchk = left.check();
            bool rightchk = right.check();
            len = left.len + right.len;
            leftChar = left.leftChar;
            rightChar = right.rightChar;
            if (leftchk && rightchk){
                if (left.rightChar == right.leftChar){
                    prefLen = sufLen = maxLen = len;
                }
                else {
                    prefLen = left.len;
                    sufLen = right.len;
                    maxLen = max(prefLen, sufLen);
                }
            }
            else if (leftchk){
                if (left.rightChar == right.leftChar){
                    prefLen = left.len + right.prefLen;
                    sufLen = right.sufLen;
                    maxLen = max(prefLen, right.maxLen);
                }
                else {
                    prefLen = left.len;
                    sufLen = right.sufLen;
                    maxLen = max(prefLen, right.maxLen);
                }
            }
            else if (rightchk){
                if (left.rightChar == right.leftChar){
                    prefLen = left.prefLen;
                    sufLen = left.sufLen + right.len;
                    maxLen = max(left.maxLen, sufLen);
                }
                else {
                    prefLen = left.prefLen;
                    sufLen = right.len;
                    maxLen = max(left.maxLen, sufLen);
                }
            }
            else {
                if (left.rightChar == right.leftChar){
                    prefLen = left.prefLen;
                    sufLen = right.sufLen;
                    maxLen = max({left.maxLen, right.maxLen, left.sufLen+right.prefLen});
                }
                else {
                    prefLen = left.prefLen;
                    sufLen = right.sufLen;
                    maxLen = max(left.maxLen, right.maxLen);
                }
            }
        }
    }
};

class Solution {
private:
    int n;
    int sz = 1;
    vector<Node> tree;

    void init(string& s){
        while (sz < n)
            sz <<= 1;
        
        tree.assign(2*sz, {0, 0, 0, 0, ' ', ' '});

        for (int i=0; i<n; i++){
            tree[sz+i].init(s[i]);
        }

        for (int i=sz-1; i>0; i--){
            tree[i].merge(tree[2*i], tree[2*i+1]);
        }
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        init(s);

        int Q = queryCharacters.size();

        vector<int> res;

        for (int q=0; q<Q; q++){
            char queryChar = queryCharacters[q];
            int idx = queryIndices[q] + sz;

            tree[idx] = {1, 1, 1, 1, queryChar, queryChar};
            idx >>= 1;
            while (idx){
                tree[idx].merge(tree[2*idx], tree[2*idx+1]);
                idx >>= 1;
            }

            res.emplace_back(tree[1].maxLen);
        }

        return res;
    }
};