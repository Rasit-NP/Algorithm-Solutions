class BST{
    public static class Node{
        int val;
        Node leftChild = null;
        Node rightChild = null;

        public Node(int val){
            this.val = val;
        }
    }

    public record Dto(
        int reorders,
        int size
    ){}

    Node head = null;

    public void push(int val){
        if (head == null){
            this.head = new Node(val);
            return;
        }
        Node now = head;
        
        while (now != null){
            if (val < now.val){
                if (now.leftChild == null){
                    now.leftChild = new Node(val);
                    return;
                }
                now = now.leftChild;
            }
            else {
                if (now.rightChild == null){
                    now.rightChild = new Node(val);
                    return;
                }
                now = now.rightChild;
            }
        }
    }

    public int count(){
        return count(head).reorders();
    }

    public Dto count(Node node){
        if (node == null){
            return new Dto(0, 0);
        }

        Dto left = count(node.leftChild);
        Dto right = count(node.rightChild);

        int leftReorders = left.reorders();
        int leftSize = left.size();
        int rightReorders = right.reorders();
        int rightSize = right.size();

        if (leftSize == 0){
            if (rightSize == 0){
                return new Dto(1, 1);
            }
            else {
                return new Dto(rightReorders, rightSize+1);
            }
        }
        else if (rightSize == 0){
            return new Dto(leftReorders, leftSize+1);
        }
        else {
            int size = leftSize + rightSize;
            long reorders = Solution.getComb(size, leftSize);

            reorders *= leftReorders;
            reorders %= Solution.MOD;
            reorders *= rightReorders;
            reorders %= Solution.MOD;

            return new Dto((int)reorders, size + 1);
        }
    }
}

class Solution {

    public static final int MOD = 1_000_000_007;
    private static final int[][] comb = new int[1001][1001];

    public static int getComb(int n, int k){
        if (comb[n][k] != 0)
            return comb[n][k];
        if (k == n || k == 0){
            comb[n][k] = 1;
            return 1;
        }
        
        comb[n][k] = getComb(n-1, k-1) + getComb(n-1, k);

        if (comb[n][k] >= MOD){
            comb[n][k] -= MOD;
        }

        return comb[n][k];
    }

    public int numOfWays(int[] nums) {
        BST bst = new BST();

        for (int num : nums){
            bst.push(num);
        }

        return bst.count() - 1;
    }
}