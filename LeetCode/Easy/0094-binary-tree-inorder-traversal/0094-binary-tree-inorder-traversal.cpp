# include <vector>
using namespace std;

class Solution {
private:
    vector<int> res;

    void dfs(TreeNode* now){
        if (now->left != nullptr){
            dfs(now->left);
        }
        res.push_back(now->val);
        if (now->right != nullptr){
            dfs(now->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        dfs(root);
        return res;
    }
};