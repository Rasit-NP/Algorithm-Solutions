class Solution {
    int res = 0;
    private int[] dfs(TreeNode node){
        if (node == null)
            return new int[2];
        int[] data = {node.val, 1};

        int[] sub1 = dfs(node.left);
        int[] sub2 = dfs(node.right);

        for (int i=0; i<2; i++)
            data[i] += sub1[i] + sub2[i];
        
        if (data[0]/data[1] == node.val)
            ++res;
        
        return data;
    }

    public int averageOfSubtree(TreeNode root) {
        dfs(root);

        return res;
    }
}