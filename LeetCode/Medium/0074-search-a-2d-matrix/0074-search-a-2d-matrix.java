class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;

        int l = 0, r = n;
        int row;

        while (r-l > 1){
            int mid = (l + r)/2;
            if (matrix[mid][0] > target){
                r = mid;
            }
            else {
                l = mid;
            }
        }

        row = l;
        l = 0;
        r = m;

        while (r-l > 1){
            int mid = (l + r) / 2;
            if (matrix[row][mid] > target){
                r = mid;
            }
            else {
                l = mid;
            }
        }

        return matrix[row][l] == target;
    }
}