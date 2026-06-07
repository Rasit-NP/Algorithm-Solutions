# include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> parents;
    unordered_map<int, pair<int, int>> childs;

    void dfs(TreeNode* now){
        if (now->left != nullptr){
            int val = now->left->val;
            int left = childs[val].first, right = childs[val].second;

            if (left != 0){
                now->left->left = new TreeNode(left);
            }
            if (right != 0){
                now->left->right = new TreeNode(right);
            }
            dfs(now->left);
        }
        if (now->right != nullptr){
            int val = now->right->val;
            int left = childs[val].first, right = childs[val].second;

            if (left != 0){
                now->right->left = new TreeNode(left);
            }
            if (right != 0){
                now->right->right = new TreeNode(right);
            }
            dfs(now->right);
        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for (vector<int>& description : descriptions){
            int x = description[1];
            int parent = description[0];
            parents[x] = parent;
            if (description[2]){
                childs[parent].first = x;
            }
            else {
                childs[parent].second = x;
            }
        }
        int rootVal = descriptions[0][0];
        while (parents[rootVal] != 0){
            rootVal = parents[rootVal];
        }

        TreeNode* root = new TreeNode(rootVal, (childs[rootVal].first != 0 ? new TreeNode(childs[rootVal].first) : nullptr), (childs[rootVal].second != 0 ? new TreeNode(childs[rootVal].second) : nullptr));

        dfs(root);

        return root;
    }
};