public class Solution {
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     * 描述
     * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
     * Example1
     *
     * Input: "bbbab"
     * Output: 4
     * Explanation:
     * One possible longest palindromic subsequence is "bbbb".
     */

    /*
    DP[i,j] = max(DP[i+1,j-1] + 1, DP[i+1,j], DP[i, j - 1])
    */

    /*
     0 1 2 3 4
    01 2 3
    1  1 2
    2    1 1
    3      1 1
    4        1
    */
    public int longestPalindromeSubseq(String s) {
        // write your code here
        int strsize = s.length();
        if (s.equals("")) {
            return 0;
        }
        int[][] DP = new int[strsize][strsize];
        for (int i = 0; i < strsize; i++) {
            DP[i][i] = 1;
            if (i + 1 < s.length()) {
                if (s.charAt(i) == s.charAt(i + 1)) {
                    DP[i][i + 1] = 2;
                }
                else {
                    DP[i][i + 1] = 1;
                }
            }
        }
        for (int windowsize = 2; windowsize < strsize; windowsize++) {
            for (int i  = 0; i + windowsize < strsize; i++) {
                int currentmax = Math.max(DP[i + 1][i + windowsize], DP[i][i + windowsize - 1]);
                if (s.charAt(i) == s.charAt(i + windowsize)) {
                    DP[i][i + windowsize] = 2 + DP[i + 1][i + windowsize - 1];
                }
                else {
                    DP[i][i + windowsize] = currentmax;
                }
            }
        }
        return DP[0][strsize - 1];
    }
}