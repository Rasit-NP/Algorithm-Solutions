# include <vector>
using namespace std;

class Solution {
private:
    vector<int> parents;
    vector<pair<int, int>> childs;

    void dfs(TreeNode* now){
        if (now->left != nullptr){
            int val = now->left->val;
            int left = childs[val].first, right = childs[val].second;

            if (left != -1){
                now->left->left = new TreeNode(left);
            }
            if (right != -1){
                now->left->right = new TreeNode(right);
            }
            dfs(now->left);
        }
        if (now->right != nullptr){
            int val = now->right->val;
            int left = childs[val].first, right = childs[val].second;

            if (left != -1){
                now->right->left = new TreeNode(left);
            }
            if (right != -1){
                now->right->right = new TreeNode(right);
            }
            dfs(now->right);
        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        parents.assign(100001, -1);
        childs.assign(100001, {-1, -1});
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
        while (parents[rootVal] != -1){
            rootVal = parents[rootVal];
        }

        TreeNode* root = new TreeNode(rootVal, (childs[rootVal].first != -1 ? new TreeNode(childs[rootVal].first) : nullptr), (childs[rootVal].second != -1 ? new TreeNode(childs[rootVal].second) : nullptr));

        dfs(root);

        return root;
    }
};