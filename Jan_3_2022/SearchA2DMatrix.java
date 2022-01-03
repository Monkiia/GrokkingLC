/*
    LeetCode 74
 */
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (target < matrix[0][0]) {
            return false;
        }
        int matrixrow = matrix.length;
        int findrow = 0;
        int rowstart = 0;
        int rowend = matrixrow - 1;

        while (rowstart + 1 < rowend) {
            int rowmid = rowstart + (rowend - rowstart) / 2;
            if (target <= matrix[rowmid][0]) {
                rowend = rowmid;
            }
            else {
                rowstart = rowmid;
            }
        }

        if (target >= matrix[rowend][0]) {
            findrow = rowend;
        }
        else {
            findrow = rowstart;
        }

        int matrixcolumn = matrix[findrow].length;
        int columnstart = 0;
        int columnend = matrixcolumn - 1;
        int findcolumn = 0;
        while (columnstart + 1 < columnend) {
            int columnmid = columnstart + (columnend - columnstart) / 2;
            if (target <= matrix[findrow][columnmid]) {
                columnend = columnmid;
            }
            else {
                columnstart = columnmid;
            }
        }
        if (target == matrix[findrow][columnend]) {
            return true;
        }
        if (target == matrix[findrow][columnstart]) {
            return true;
        }
        return false;
    }
}